/*
 *
 *    Copyright (c) 2020 Project CHIP Authors
 *    All rights reserved.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

#include <stdio.h>
#include <stdlib.h>

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>

#include <FreeRTOS.h>

#include "AppConfig.h"
#include <AppTask.h>
#include <easyflash.h>
#include <lib/support/CHIPMem.h>
#include <lib/support/CHIPPlatformMemory.h>

#include <blog.h>
extern "C" {

#ifdef BL702_ENABLE
#include <bl702_glb.h>
#include <bl702_hbn.h>
#include "bl_wireless.h"
#elif defined(BL602_ENABLE)
#include <wifi_mgmr_ext.h>
#include "bl_wifi.h"
#endif
#include <bl_irq.h>
#include <bl_rtc.h>
#include <bl_sec.h>
#include <bl_sys.h>
#ifdef CFG_USE_PSRAM
#include <bl_psram.h>
#endif
#include <bl_timer.h>
#include <hal_board.h>
#include <hal_boot2.h>

#include <hosal_uart.h>

#include "board.h"
}

using namespace ::chip;
using namespace ::chip::Inet;
using namespace ::chip::DeviceLayer;

#define UNUSED_PARAMETER(a) (a = a)

HOSAL_UART_DEV_DECL(uart_stdio, CHIP_UART_PORT, CHIP_UART_PIN_TX, CHIP_UART_PIN_RX, CHIP_UART_BAUDRATE);

volatile int apperror_cnt;

#ifdef SYS_AOS_LOOP_ENABLE
extern "C" void aos_loop_start(void);
#endif

// ================================================================================
// App Error
//=================================================================================
void appError(int err)
{
    ChipLogProgress(NotSpecified, "!!!!!!!!!!!! App Critical Error: %d !!!!!!!!!!!", err);
    portDISABLE_INTERRUPTS();
    while (1)
        ;
}

void appError(CHIP_ERROR error)
{
    appError(static_cast<int>(error.AsInteger()));
}

// ================================================================================
// FreeRTOS Callbacks
// ================================================================================
extern "C" unsigned int sleep(unsigned int seconds)
{
    const TickType_t xDelay = 1000 * seconds / portTICK_PERIOD_MS;
    vTaskDelay(xDelay);
    return 0;
}

extern "C" void vApplicationStackOverflowHook(TaskHandle_t xTask, char * pcTaskName)
{
    ChipLogProgress(NotSpecified, "Stack Overflow checked. Stack name %s", pcTaskName);
    while (1)
    {
        /*empty here*/
    }
}

extern "C" void vApplicationMallocFailedHook(void)
{
    ChipLogProgress(NotSpecified, "Memory Allocate Failed. Current left size is %d bytes", xPortGetFreeHeapSize());
    while (1)
    {
        /*empty here*/
    }
}

extern "C" void vApplicationIdleHook(void)
{
    //    bl_wdt_feed();
    __asm volatile("   wfi     ");
}

extern "C" void vApplicationGetIdleTaskMemory(StaticTask_t ** ppxIdleTaskTCBBuffer, StackType_t ** ppxIdleTaskStackBuffer,
                                              uint32_t * pulIdleTaskStackSize)
{
    /* If the buffers to be provided to the Idle task are declared inside this
    function then they must be declared static - otherwise they will be allocated on
    the stack and so not exists after this function exits. */
    static StaticTask_t xIdleTaskTCB;
    static StackType_t uxIdleTaskStack[configMINIMAL_STACK_SIZE];

    /* Pass out a pointer to the StaticTask_t structure in which the Idle task's
    state will be stored. */
    *ppxIdleTaskTCBBuffer = &xIdleTaskTCB;

    /* Pass out the array that will be used as the Idle task's stack. */
    *ppxIdleTaskStackBuffer = uxIdleTaskStack;

    /* Pass out the size of the array pointed to by *ppxIdleTaskStackBuffer.
    Note that, as the array is necessarily of type StackType_t,
    configMINIMAL_STACK_SIZE is specified in words, not bytes. */
    *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
}

/* configSUPPORT_STATIC_ALLOCATION and configUSE_TIMERS are both set to 1, so the
application must provide an implementation of vApplicationGetTimerTaskMemory()
to provide the memory that is used by the Timer service task. */
extern "C" void vApplicationGetTimerTaskMemory(StaticTask_t ** ppxTimerTaskTCBBuffer, StackType_t ** ppxTimerTaskStackBuffer,
                                               uint32_t * pulTimerTaskStackSize)
{
    /* If the buffers to be provided to the Timer task are declared inside this
    function then they must be declared static - otherwise they will be allocated on
    the stack and so not exists after this function exits. */
    static StaticTask_t xTimerTaskTCB;
    static StackType_t uxTimerTaskStack[configMINIMAL_STACK_SIZE * 3 / 2];

    /* Pass out a pointer to the StaticTask_t structure in which the Timer
    task's state will be stored. */
    *ppxTimerTaskTCBBuffer = &xTimerTaskTCB;

    /* Pass out the array that will be used as the Timer task's stack. */
    *ppxTimerTaskStackBuffer = uxTimerTaskStack;

    /* Pass out the size of the array pointed to by *ppxTimerTaskStackBuffer.
    Note that, as the array is necessarily of type StackType_t,
    configTIMER_TASK_STACK_DEPTH is specified in words, not bytes. */
    *pulTimerTaskStackSize = configMINIMAL_STACK_SIZE * 3 / 2;
}

#if (configUSE_TICK_HOOK != 0)
extern "C" void vApplicationTickHook(void)
{
#if defined(CFG_USB_CDC_ENABLE)
    extern void usb_cdc_monitor(void);
    usb_cdc_monitor();
#endif
}
#endif

extern "C" void vApplicationSleep(TickType_t xExpectedIdleTime) {}

extern "C" void user_vAssertCalled(void) __attribute__((weak, alias("vAssertCalled")));
extern "C" void vAssertCalled(void)
{
    void * ra = (void *) __builtin_return_address(0);

    taskDISABLE_INTERRUPTS();
    ChipLogProgress(NotSpecified, "vAssertCalled, ra= %p", ra);
    while (1)
        ;
}

// ================================================================================
// Main Code
// ================================================================================
extern "C" uint8_t _heap_start;
extern "C" size_t _heap_size; // @suppress("Type cannot be resolved")

#ifdef BL602_ENABLE
extern uint8_t _heap_wifi_start;
extern uint8_t _heap_wifi_size; // @suppress("Type cannot be resolved")
static HeapRegion_t xHeapRegions[] = {
    { &_heap_start, (unsigned int) &_heap_size }, // set on runtime
    { &_heap_wifi_start, (unsigned int) &_heap_wifi_size },
    { NULL, 0 } /* Terminates the array. */
};
#elif defined(BL702_ENABLE)
static constexpr HeapRegion_t xHeapRegions[] = {
    { &_heap_start, (size_t) &_heap_size }, // set on runtime
    { NULL, 0 }                             /* Terminates the array. */
};
#endif

#ifdef CFG_USE_PSRAM

extern "C" uint32_t __psram_bss_init_start;
extern "C" uint32_t __psram_bss_init_end;

static uint32_t __attribute__((section(".rsvd_data"))) psram_reset_count;

extern "C" uint8_t _heap3_start;
extern "C" size_t _heap3_size; // @suppress("Type cannot be resolved")
static constexpr HeapRegion_t xPsramHeapRegions[] = {
    { &_heap3_start, (size_t) &_heap3_size }, { NULL, 0 } /* Terminates the array. */
};

extern "C" size_t get_heap3_size(void)
{
    return (size_t) &_heap3_size;
}

extern "C" void do_psram_test()
{
    static constexpr char teststr[] = "bouffalolab psram test string";

    do
    {
        uint8_t * pheap = &_heap3_start;
        size_t size     = (size_t) &_heap3_size;

        size = size > sizeof(teststr) ? sizeof(teststr) : size;
        memset(pheap, 0, size);
        if (pheap[0] != 0)
        {
            break;
        }

        memcpy(pheap, teststr, size);
        if (0 != memcmp(pheap, teststr, size))
        {
            break;
        }

        arch_memset4(&__psram_bss_init_start, 0, &__psram_bss_init_end - &__psram_bss_init_start);

        psram_reset_count = 0xffffff00;
        return;
    } while (0);

    if ((psram_reset_count & 0xffffff00) != 0xffffff00)
    {
        psram_reset_count = 0xffffff00;
    }

    if ((psram_reset_count & 0x000000ff) > 3)
    {
        ChipLogError(NotSpecified, "PSRAM is still failed to initialize after %ld system reset", psram_reset_count & 0x000000ff);
        vAssertCalled();
    }

    psram_reset_count = ((psram_reset_count & 0x000000ff) + 1) | 0xffffff00;
    bl_sys_reset_system();
}
#endif

extern "C" void setup_heap()
{
#ifdef BL702_ENABLE
    bl_sys_em_config();
#endif
    vPortDefineHeapRegions(xHeapRegions);
}

extern "C" size_t get_heap_size(void)
{
    return (size_t) &_heap_size;
}

extern "C" void app_init(void)
{
    bl_sys_init();

    bl_sys_early_init();

    hosal_uart_init(&uart_stdio);

    ChipLogProgress(NotSpecified, "==================================================");
    ChipLogProgress(NotSpecified, "bouffalolab chip-lighting-example, built at " __DATE__ " " __TIME__);
    ChipLogProgress(NotSpecified, "==================================================");

    blog_init();
    bl_irq_init();
    bl_sec_init();
#ifdef BL702_ENABLE
    bl_timer_init();
#endif
#ifdef CFG_USE_PSRAM
    bl_psram_init();
    do_psram_test();
#endif

    // bl_rtc_init();
    hal_boot2_init();

    /* board config is set after system is init*/
    hal_board_cfg(0);
    //    hosal_dma_init();

#ifdef CFG_USE_PSRAM
    vPortDefineHeapRegionsPsram(xPsramHeapRegions);
    ChipLogProgress(NotSpecified, "Heap %u@%p, %u@%p", (unsigned int) &_heap_size, &_heap_start, (unsigned int) &_heap3_size,
                    &_heap3_start);
#else
    ChipLogProgress(NotSpecified, "Heap %u@%p", (unsigned int) &_heap_size, &_heap_start);
#endif
#ifdef BL602_ENABLE
    wifi_td_diagnosis_init();
#endif
}

uint16_t discriminator_mac_g;
uint8_t sn_mac_g[13];

extern "C" void get_mac_init(void)
{
    uint8_t mac[6];
    uint32_t setup_pin_code_mac_g;
    int ret;

    memset(mac, 0, sizeof(mac));
#ifdef BL602_ENABLE
    bl_wifi_mac_addr_get(mac);
#elif defined(BL702_ENABLE)
    bl_wireless_mac_addr_get(mac);
#endif
    ChipLogProgress(NotSpecified, " get MAC #### %02X:%02X:%02X:%02X:%02X:%02X ####\r\n", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
    strncpy(sn_mac_g, mac, 6);
    itoa(mac[0],sn_mac_g,16);
    itoa(mac[1],sn_mac_g+2,16);
    itoa(mac[2],sn_mac_g+4,16);
    itoa(mac[3],sn_mac_g+6,16);
    itoa(mac[4],sn_mac_g+8,16);
    itoa(mac[5],sn_mac_g+10,16);
    sn_mac_g[12] = 0;

    setup_pin_code_mac_g = (((mac[0] << 8) + mac[1]) ^ ((mac[1] << 8) + mac[2])) & 0x7FFF;
    setup_pin_code_mac_g <<= 12;
    setup_pin_code_mac_g += (mac[3] << 4) + ((mac[4] & 0xF0) >> 4) + 1;
    discriminator_mac_g = ((mac[4] & 0x0F) << 8) + mac[5] + 1;

    *((uint8_t*)&discriminator_mac_g+1) ^= *(uint8_t*)&discriminator_mac_g;
    *((uint8_t*)&setup_pin_code_mac_g+1) ^= *(uint8_t*)&setup_pin_code_mac_g;
    *((uint8_t*)&setup_pin_code_mac_g+2) ^= *(uint8_t*)&setup_pin_code_mac_g;
    *((uint8_t*)&setup_pin_code_mac_g+3) ^= *(uint8_t*)&setup_pin_code_mac_g;
    discriminator_mac_g &= 0xFFF;
    setup_pin_code_mac_g &= 0x7FFFFFF;
    while(++discriminator_mac_g<3);
    while(++setup_pin_code_mac_g<3);
    while(--discriminator_mac_g>0xFFF);
    while(--setup_pin_code_mac_g>0x7FFFFFF);
    discriminator_mac_g = (setup_pin_code_mac_g % discriminator_mac_g);
    while(++discriminator_mac_g<3);
    while(--discriminator_mac_g>0xFFF);

    ChipLogProgress(NotSpecified, "######## discriminator = %03X ########\r\n", discriminator_mac_g);
}

extern "C" void START_ENTRY(void)
{
    app_init();

    easyflash_init();

    ChipLogProgress(NotSpecified, "Init CHIP Memory");
    chip::Platform::MemoryInit(NULL, 0);

#ifdef SYS_AOS_LOOP_ENABLE
    ChipLogProgress(NotSpecified, "Starting AOS loop Task");
    aos_loop_start();
#else
#if defined(CFG_USB_CDC_ENABLE)
    extern void usb_cdc_start(int fd_console);
    usb_cdc_start(-1);
#endif
#endif

    ChipLogProgress(NotSpecified, "Starting App Task");
    get_mac_init();
    StartAppTask();

    ChipLogProgress(NotSpecified, "Starting OS Scheduler...");
    vTaskStartScheduler();

    // Should never get here.
    ChipLogError(NotSpecified, "Starting OS Scheduler failed");
    appError(0);
}
