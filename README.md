# What is Matter?

Matter (formerly Project Connected Home over IP, or Project CHIP) is a new
Working Group within the Connectivity Standards Alliance (CSA, formerly Zigbee
Alliance). This Working Group plans to develop and promote the adoption of a
new, royalty-free connectivity standard to increase compatibility among smart
home products, with security as a fundamental design tenet.

The goal of the Matter project is to simplify development for manufacturers and
increase compatibility for consumers. The project is built around a shared
belief that smart home devices should be secure, reliable, and seamless to use.
By building upon Internet Protocol (IP), the project aims to enable
communication across smart home devices, mobile apps, and cloud services and to
define a specific set of IP-based networking technologies for device
certification.



# Third Reality Matter Projects

Third Reality  has actively participated in Matter. By the end of 2022, it has just 
developed two night light products, providing open source code and hardware 
for interested developers to download code, compile and burn firmware 
to the light for testing. Users can voice control lights (switch lights, adjust colors, 
and brightness) on HomePod mini, HomePod, Google Nest and other speakers that 
support Matter. Needless to say, users can also control these lights through 
their mobile phones.

These two lamps have PIR motion sensor and light sensor inside. With the help of 
these sensors, developers can directly develop practical night light lighting products. 
Third Reality  will open source all relevant code at an appropriate time to facilitate 
developers. 

Third Reality keep updating the software and hardware of the existing Matter 
products, and provide users with more reference examples (in fact, it is a product with 
complete functions, and it will be easier for users to modify the code on this basis, 
and can achieve full customization functions).  At the same time, develop new products 
that support Matter standard.

Third Reality will pay attention to the progress of the Matter and upgrade with it 
synchronously, so that users can experience the latest version of Matter earlier. 
Matter is as vibrant as the Amazon rainforest. Let's go ahead.



# Development Environment



### Recommended OS

`Ubuntu` 22.04 LTS

### Install Dependencies

`sudo apt-get install git gcc g++ pkg-config libssl-dev libdbus-1-dev \`

​     `libglib2.0-dev libavahi-client-dev ninja-build python3-venv python3-dev \`

​    `python3-pip unzip libgirepository1.0-dev libcairo2-dev libreadline-dev`

### Download Code

`git clone https://github.com/thirdreality/nightlight_mt.git`

`cd nightlight_mt`

`git submodule update --init --recursive`

`source ./scripts/activate.sh`

If this script says the environment is out of date, it can be updated by running:
`source ./scripts/bootstrap.sh` 

### Install Bouffalo Lab SDK

`cd third_party/bouffalolab/repo`

`sudo bash scripts/setup.sh`

### Set Environment Variables

`export BOUFFALOLAB_SDK_ROOT=/opt/bouffalolab_sdk`

### Compile BL602 ( main branch)

`./scripts/build/build_examples.py --target bouffalolab-bl602-iot-matter-v1-light build`

### Compile BL706 ( main branch)

`./scripts/examples/gn_bouffalolab_example.sh lighting-app out/bouffalolab-bl706-night-light-light BL706-NIGHT-LIGHT module_type=BL706C-22 enable_cdc_module=true`

### Compiled Results

at ./out directory



# Burn firmware

### Get Burning Tool

The burning tool "**Bouffalo Lab Dev Cube**" can be downloaded from the bouffalo official website 

https://dev.bouffalolab.com/download

or found under the tools directory of the project path.

### Burn BL602

1. press and hold the key on the 602 lamp
2. press the reset button on the debugging board 
3. release the lamp key to enter the burning mode
4. run BLDevCube.exe ( at burning tool directory ) on Windows OS 
5. Set parameters as shown in the following screenshot
6. click Create & Download button
7. wait until the progress bar is 100%, which means the burning is completed

![](C:\Users\aibicn\AppData\Roaming\Typora\typora-user-images\image-20221230225038480.png)



### Burn BL706



# Control the Night Light

### Use iPhone and HomePod mini

### Factory Reset

<!--(To be continued)-->
