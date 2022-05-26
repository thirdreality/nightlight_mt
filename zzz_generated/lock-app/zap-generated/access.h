/*
 *
 *    Copyright (c) 2022 Project CHIP Authors
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

// THIS FILE IS GENERATED BY ZAP

// Prevent multiple inclusion
#pragma once

#include <app/util/privilege-storage.h>

// Prevent changing generated format
// clang-format off

////////////////////////////////////////////////////////////////////////////////

// Parallel array data (*cluster*, attribute, privilege) for read attribute
#define GENERATED_ACCESS_READ_ATTRIBUTE__CLUSTER { \
    31, /* Cluster: Access Control, Attribute: ACL, Privilege: administer */ \
    31, /* Cluster: Access Control, Attribute: Extension, Privilege: administer */ \
    /* Cluster: Access Control, Attribute: SubjectsPerAccessControlEntry, Privilege: view */ \
    /* Cluster: Access Control, Attribute: TargetsPerAccessControlEntry, Privilege: view */ \
    /* Cluster: Access Control, Attribute: AccessControlEntriesPerFabric, Privilege: view */ \
    /* Cluster: Basic, Attribute: NodeLabel, Privilege: view */ \
    /* Cluster: Basic, Attribute: Location, Privilege: view */ \
    /* Cluster: Basic, Attribute: LocalConfigDisabled, Privilege: view */ \
    /* Cluster: Door Lock, Attribute: Language, Privilege: view */ \
    /* Cluster: Door Lock, Attribute: AutoRelockTime, Privilege: view */ \
    /* Cluster: Door Lock, Attribute: SoundVolume, Privilege: view */ \
    /* Cluster: Door Lock, Attribute: OperatingMode, Privilege: view */ \
    /* Cluster: Door Lock, Attribute: EnableOneTouchLocking, Privilege: view */ \
    /* Cluster: Door Lock, Attribute: EnablePrivacyModeButton, Privilege: view */ \
    /* Cluster: Door Lock, Attribute: WrongCodeEntryLimit, Privilege: view */ \
    /* Cluster: Door Lock, Attribute: UserCodeTemporaryDisableTime, Privilege: view */ \
    /* Cluster: Door Lock, Attribute: RequirePINforRemoteOperation, Privilege: view */ \
    /* Cluster: General Commissioning, Attribute: Breadcrumb, Privilege: view */ \
    49, /* Cluster: Network Commissioning, Attribute: MaxNetworks, Privilege: administer */ \
    49, /* Cluster: Network Commissioning, Attribute: Networks, Privilege: administer */ \
    /* Cluster: Network Commissioning, Attribute: InterfaceEnabled, Privilege: view */ \
    49, /* Cluster: Network Commissioning, Attribute: LastNetworkingStatus, Privilege: administer */ \
    49, /* Cluster: Network Commissioning, Attribute: LastNetworkID, Privilege: administer */ \
    49, /* Cluster: Network Commissioning, Attribute: LastConnectErrorValue, Privilege: administer */ \
    /* Cluster: On/Off, Attribute: StartUpOnOff, Privilege: view */ \
    62, /* Cluster: Operational Credentials, Attribute: NOCs, Privilege: administer */ \
    /* Cluster: User Label, Attribute: label list, Privilege: view */ \
}

// Parallel array data (cluster, *attribute*, privilege) for read attribute
#define GENERATED_ACCESS_READ_ATTRIBUTE__ATTRIBUTE { \
    0, /* Cluster: Access Control, Attribute: ACL, Privilege: administer */ \
    1, /* Cluster: Access Control, Attribute: Extension, Privilege: administer */ \
    /* Cluster: Access Control, Attribute: SubjectsPerAccessControlEntry, Privilege: view */ \
    /* Cluster: Access Control, Attribute: TargetsPerAccessControlEntry, Privilege: view */ \
    /* Cluster: Access Control, Attribute: AccessControlEntriesPerFabric, Privilege: view */ \
    /* Cluster: Basic, Attribute: NodeLabel, Privilege: view */ \
    /* Cluster: Basic, Attribute: Location, Privilege: view */ \
    /* Cluster: Basic, Attribute: LocalConfigDisabled, Privilege: view */ \
    /* Cluster: Door Lock, Attribute: Language, Privilege: view */ \
    /* Cluster: Door Lock, Attribute: AutoRelockTime, Privilege: view */ \
    /* Cluster: Door Lock, Attribute: SoundVolume, Privilege: view */ \
    /* Cluster: Door Lock, Attribute: OperatingMode, Privilege: view */ \
    /* Cluster: Door Lock, Attribute: EnableOneTouchLocking, Privilege: view */ \
    /* Cluster: Door Lock, Attribute: EnablePrivacyModeButton, Privilege: view */ \
    /* Cluster: Door Lock, Attribute: WrongCodeEntryLimit, Privilege: view */ \
    /* Cluster: Door Lock, Attribute: UserCodeTemporaryDisableTime, Privilege: view */ \
    /* Cluster: Door Lock, Attribute: RequirePINforRemoteOperation, Privilege: view */ \
    /* Cluster: General Commissioning, Attribute: Breadcrumb, Privilege: view */ \
    0, /* Cluster: Network Commissioning, Attribute: MaxNetworks, Privilege: administer */ \
    1, /* Cluster: Network Commissioning, Attribute: Networks, Privilege: administer */ \
    /* Cluster: Network Commissioning, Attribute: InterfaceEnabled, Privilege: view */ \
    5, /* Cluster: Network Commissioning, Attribute: LastNetworkingStatus, Privilege: administer */ \
    6, /* Cluster: Network Commissioning, Attribute: LastNetworkID, Privilege: administer */ \
    7, /* Cluster: Network Commissioning, Attribute: LastConnectErrorValue, Privilege: administer */ \
    /* Cluster: On/Off, Attribute: StartUpOnOff, Privilege: view */ \
    0, /* Cluster: Operational Credentials, Attribute: NOCs, Privilege: administer */ \
    /* Cluster: User Label, Attribute: label list, Privilege: view */ \
}

// Parallel array data (cluster, attribute, *privilege*) for read attribute
#define GENERATED_ACCESS_READ_ATTRIBUTE__PRIVILEGE { \
    kMatterAccessPrivilegeAdminister, /* Cluster: Access Control, Attribute: ACL, Privilege: administer */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: Access Control, Attribute: Extension, Privilege: administer */ \
    /* Cluster: Access Control, Attribute: SubjectsPerAccessControlEntry, Privilege: view */ \
    /* Cluster: Access Control, Attribute: TargetsPerAccessControlEntry, Privilege: view */ \
    /* Cluster: Access Control, Attribute: AccessControlEntriesPerFabric, Privilege: view */ \
    /* Cluster: Basic, Attribute: NodeLabel, Privilege: view */ \
    /* Cluster: Basic, Attribute: Location, Privilege: view */ \
    /* Cluster: Basic, Attribute: LocalConfigDisabled, Privilege: view */ \
    /* Cluster: Door Lock, Attribute: Language, Privilege: view */ \
    /* Cluster: Door Lock, Attribute: AutoRelockTime, Privilege: view */ \
    /* Cluster: Door Lock, Attribute: SoundVolume, Privilege: view */ \
    /* Cluster: Door Lock, Attribute: OperatingMode, Privilege: view */ \
    /* Cluster: Door Lock, Attribute: EnableOneTouchLocking, Privilege: view */ \
    /* Cluster: Door Lock, Attribute: EnablePrivacyModeButton, Privilege: view */ \
    /* Cluster: Door Lock, Attribute: WrongCodeEntryLimit, Privilege: view */ \
    /* Cluster: Door Lock, Attribute: UserCodeTemporaryDisableTime, Privilege: view */ \
    /* Cluster: Door Lock, Attribute: RequirePINforRemoteOperation, Privilege: view */ \
    /* Cluster: General Commissioning, Attribute: Breadcrumb, Privilege: view */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: Network Commissioning, Attribute: MaxNetworks, Privilege: administer */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: Network Commissioning, Attribute: Networks, Privilege: administer */ \
    /* Cluster: Network Commissioning, Attribute: InterfaceEnabled, Privilege: view */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: Network Commissioning, Attribute: LastNetworkingStatus, Privilege: administer */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: Network Commissioning, Attribute: LastNetworkID, Privilege: administer */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: Network Commissioning, Attribute: LastConnectErrorValue, Privilege: administer */ \
    /* Cluster: On/Off, Attribute: StartUpOnOff, Privilege: view */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: Operational Credentials, Attribute: NOCs, Privilege: administer */ \
    /* Cluster: User Label, Attribute: label list, Privilege: view */ \
}

////////////////////////////////////////////////////////////////////////////////

// Parallel array data (*cluster*, attribute, privilege) for write attribute
#define GENERATED_ACCESS_WRITE_ATTRIBUTE__CLUSTER { \
    31, /* Cluster: Access Control, Attribute: ACL, Privilege: administer */ \
    31, /* Cluster: Access Control, Attribute: Extension, Privilege: administer */ \
    40, /* Cluster: Basic, Attribute: NodeLabel, Privilege: manage */ \
    40, /* Cluster: Basic, Attribute: Location, Privilege: administer */ \
    40, /* Cluster: Basic, Attribute: LocalConfigDisabled, Privilege: manage */ \
    257, /* Cluster: Door Lock, Attribute: Language, Privilege: manage */ \
    257, /* Cluster: Door Lock, Attribute: AutoRelockTime, Privilege: manage */ \
    257, /* Cluster: Door Lock, Attribute: SoundVolume, Privilege: manage */ \
    257, /* Cluster: Door Lock, Attribute: OperatingMode, Privilege: manage */ \
    257, /* Cluster: Door Lock, Attribute: EnableOneTouchLocking, Privilege: manage */ \
    257, /* Cluster: Door Lock, Attribute: EnablePrivacyModeButton, Privilege: manage */ \
    257, /* Cluster: Door Lock, Attribute: WrongCodeEntryLimit, Privilege: administer */ \
    257, /* Cluster: Door Lock, Attribute: UserCodeTemporaryDisableTime, Privilege: administer */ \
    257, /* Cluster: Door Lock, Attribute: RequirePINforRemoteOperation, Privilege: administer */ \
    48, /* Cluster: General Commissioning, Attribute: Breadcrumb, Privilege: administer */ \
    49, /* Cluster: Network Commissioning, Attribute: InterfaceEnabled, Privilege: administer */ \
    6, /* Cluster: On/Off, Attribute: StartUpOnOff, Privilege: manage */ \
    65, /* Cluster: User Label, Attribute: label list, Privilege: manage */ \
}

// Parallel array data (cluster, *attribute*, privilege) for write attribute
#define GENERATED_ACCESS_WRITE_ATTRIBUTE__ATTRIBUTE { \
    0, /* Cluster: Access Control, Attribute: ACL, Privilege: administer */ \
    1, /* Cluster: Access Control, Attribute: Extension, Privilege: administer */ \
    5, /* Cluster: Basic, Attribute: NodeLabel, Privilege: manage */ \
    6, /* Cluster: Basic, Attribute: Location, Privilege: administer */ \
    16, /* Cluster: Basic, Attribute: LocalConfigDisabled, Privilege: manage */ \
    33, /* Cluster: Door Lock, Attribute: Language, Privilege: manage */ \
    35, /* Cluster: Door Lock, Attribute: AutoRelockTime, Privilege: manage */ \
    36, /* Cluster: Door Lock, Attribute: SoundVolume, Privilege: manage */ \
    37, /* Cluster: Door Lock, Attribute: OperatingMode, Privilege: manage */ \
    41, /* Cluster: Door Lock, Attribute: EnableOneTouchLocking, Privilege: manage */ \
    43, /* Cluster: Door Lock, Attribute: EnablePrivacyModeButton, Privilege: manage */ \
    48, /* Cluster: Door Lock, Attribute: WrongCodeEntryLimit, Privilege: administer */ \
    49, /* Cluster: Door Lock, Attribute: UserCodeTemporaryDisableTime, Privilege: administer */ \
    51, /* Cluster: Door Lock, Attribute: RequirePINforRemoteOperation, Privilege: administer */ \
    0, /* Cluster: General Commissioning, Attribute: Breadcrumb, Privilege: administer */ \
    4, /* Cluster: Network Commissioning, Attribute: InterfaceEnabled, Privilege: administer */ \
    16387, /* Cluster: On/Off, Attribute: StartUpOnOff, Privilege: manage */ \
    0, /* Cluster: User Label, Attribute: label list, Privilege: manage */ \
}

// Parallel array data (cluster, attribute, *privilege*) for write attribute
#define GENERATED_ACCESS_WRITE_ATTRIBUTE__PRIVILEGE { \
    kMatterAccessPrivilegeAdminister, /* Cluster: Access Control, Attribute: ACL, Privilege: administer */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: Access Control, Attribute: Extension, Privilege: administer */ \
    kMatterAccessPrivilegeManage, /* Cluster: Basic, Attribute: NodeLabel, Privilege: manage */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: Basic, Attribute: Location, Privilege: administer */ \
    kMatterAccessPrivilegeManage, /* Cluster: Basic, Attribute: LocalConfigDisabled, Privilege: manage */ \
    kMatterAccessPrivilegeManage, /* Cluster: Door Lock, Attribute: Language, Privilege: manage */ \
    kMatterAccessPrivilegeManage, /* Cluster: Door Lock, Attribute: AutoRelockTime, Privilege: manage */ \
    kMatterAccessPrivilegeManage, /* Cluster: Door Lock, Attribute: SoundVolume, Privilege: manage */ \
    kMatterAccessPrivilegeManage, /* Cluster: Door Lock, Attribute: OperatingMode, Privilege: manage */ \
    kMatterAccessPrivilegeManage, /* Cluster: Door Lock, Attribute: EnableOneTouchLocking, Privilege: manage */ \
    kMatterAccessPrivilegeManage, /* Cluster: Door Lock, Attribute: EnablePrivacyModeButton, Privilege: manage */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: Door Lock, Attribute: WrongCodeEntryLimit, Privilege: administer */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: Door Lock, Attribute: UserCodeTemporaryDisableTime, Privilege: administer */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: Door Lock, Attribute: RequirePINforRemoteOperation, Privilege: administer */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: General Commissioning, Attribute: Breadcrumb, Privilege: administer */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: Network Commissioning, Attribute: InterfaceEnabled, Privilege: administer */ \
    kMatterAccessPrivilegeManage, /* Cluster: On/Off, Attribute: StartUpOnOff, Privilege: manage */ \
    kMatterAccessPrivilegeManage, /* Cluster: User Label, Attribute: label list, Privilege: manage */ \
}

////////////////////////////////////////////////////////////////////////////////

// Parallel array data (*cluster*, command, privilege) for invoke command
#define GENERATED_ACCESS_INVOKE_COMMAND__CLUSTER { \
    60, /* Cluster: AdministratorCommissioning, Command: OpenCommissioningWindow, Privilege: administer */ \
    60, /* Cluster: AdministratorCommissioning, Command: OpenBasicCommissioningWindow, Privilege: administer */ \
    60, /* Cluster: AdministratorCommissioning, Command: RevokeCommissioning, Privilege: administer */ \
    257, /* Cluster: Door Lock, Command: SetWeekDaySchedule, Privilege: administer */ \
    257, /* Cluster: Door Lock, Command: GetWeekDaySchedule, Privilege: administer */ \
    257, /* Cluster: Door Lock, Command: ClearWeekDaySchedule, Privilege: administer */ \
    257, /* Cluster: Door Lock, Command: SetYearDaySchedule, Privilege: administer */ \
    257, /* Cluster: Door Lock, Command: GetYearDaySchedule, Privilege: administer */ \
    257, /* Cluster: Door Lock, Command: ClearYearDaySchedule, Privilege: administer */ \
    257, /* Cluster: Door Lock, Command: SetHolidaySchedule, Privilege: administer */ \
    257, /* Cluster: Door Lock, Command: GetHolidaySchedule, Privilege: administer */ \
    257, /* Cluster: Door Lock, Command: ClearHolidaySchedule, Privilege: administer */ \
    257, /* Cluster: Door Lock, Command: SetUser, Privilege: administer */ \
    257, /* Cluster: Door Lock, Command: GetUser, Privilege: administer */ \
    257, /* Cluster: Door Lock, Command: ClearUser, Privilege: administer */ \
    257, /* Cluster: Door Lock, Command: SetCredential, Privilege: administer */ \
    257, /* Cluster: Door Lock, Command: GetCredentialStatus, Privilege: administer */ \
    257, /* Cluster: Door Lock, Command: ClearCredential, Privilege: administer */ \
    48, /* Cluster: General Commissioning, Command: ArmFailSafe, Privilege: administer */ \
    48, /* Cluster: General Commissioning, Command: SetRegulatoryConfig, Privilege: administer */ \
    48, /* Cluster: General Commissioning, Command: CommissioningComplete, Privilege: administer */ \
    4, /* Cluster: Groups, Command: AddGroup, Privilege: manage */ \
    4, /* Cluster: Groups, Command: RemoveGroup, Privilege: manage */ \
    4, /* Cluster: Groups, Command: RemoveAllGroups, Privilege: manage */ \
    4, /* Cluster: Groups, Command: AddGroupIfIdentifying, Privilege: manage */ \
    3, /* Cluster: Identify, Command: Identify, Privilege: manage */ \
    49, /* Cluster: Network Commissioning, Command: ScanNetworks, Privilege: administer */ \
    49, /* Cluster: Network Commissioning, Command: AddOrUpdateWiFiNetwork, Privilege: administer */ \
    49, /* Cluster: Network Commissioning, Command: AddOrUpdateThreadNetwork, Privilege: administer */ \
    49, /* Cluster: Network Commissioning, Command: RemoveNetwork, Privilege: administer */ \
    49, /* Cluster: Network Commissioning, Command: ConnectNetwork, Privilege: administer */ \
    49, /* Cluster: Network Commissioning, Command: ReorderNetwork, Privilege: administer */ \
    62, /* Cluster: Operational Credentials, Command: AttestationRequest, Privilege: administer */ \
    62, /* Cluster: Operational Credentials, Command: CertificateChainRequest, Privilege: administer */ \
    62, /* Cluster: Operational Credentials, Command: CSRRequest, Privilege: administer */ \
    62, /* Cluster: Operational Credentials, Command: AddNOC, Privilege: administer */ \
    62, /* Cluster: Operational Credentials, Command: UpdateNOC, Privilege: administer */ \
    62, /* Cluster: Operational Credentials, Command: UpdateFabricLabel, Privilege: administer */ \
    62, /* Cluster: Operational Credentials, Command: RemoveFabric, Privilege: administer */ \
    62, /* Cluster: Operational Credentials, Command: AddTrustedRootCertificate, Privilege: administer */ \
    62, /* Cluster: Operational Credentials, Command: RemoveTrustedRootCertificate, Privilege: administer */ \
}

// Parallel array data (cluster, *command*, privilege) for invoke command
#define GENERATED_ACCESS_INVOKE_COMMAND__COMMAND { \
    0, /* Cluster: AdministratorCommissioning, Command: OpenCommissioningWindow, Privilege: administer */ \
    1, /* Cluster: AdministratorCommissioning, Command: OpenBasicCommissioningWindow, Privilege: administer */ \
    2, /* Cluster: AdministratorCommissioning, Command: RevokeCommissioning, Privilege: administer */ \
    11, /* Cluster: Door Lock, Command: SetWeekDaySchedule, Privilege: administer */ \
    12, /* Cluster: Door Lock, Command: GetWeekDaySchedule, Privilege: administer */ \
    13, /* Cluster: Door Lock, Command: ClearWeekDaySchedule, Privilege: administer */ \
    14, /* Cluster: Door Lock, Command: SetYearDaySchedule, Privilege: administer */ \
    15, /* Cluster: Door Lock, Command: GetYearDaySchedule, Privilege: administer */ \
    16, /* Cluster: Door Lock, Command: ClearYearDaySchedule, Privilege: administer */ \
    17, /* Cluster: Door Lock, Command: SetHolidaySchedule, Privilege: administer */ \
    18, /* Cluster: Door Lock, Command: GetHolidaySchedule, Privilege: administer */ \
    19, /* Cluster: Door Lock, Command: ClearHolidaySchedule, Privilege: administer */ \
    26, /* Cluster: Door Lock, Command: SetUser, Privilege: administer */ \
    27, /* Cluster: Door Lock, Command: GetUser, Privilege: administer */ \
    29, /* Cluster: Door Lock, Command: ClearUser, Privilege: administer */ \
    34, /* Cluster: Door Lock, Command: SetCredential, Privilege: administer */ \
    36, /* Cluster: Door Lock, Command: GetCredentialStatus, Privilege: administer */ \
    38, /* Cluster: Door Lock, Command: ClearCredential, Privilege: administer */ \
    0, /* Cluster: General Commissioning, Command: ArmFailSafe, Privilege: administer */ \
    2, /* Cluster: General Commissioning, Command: SetRegulatoryConfig, Privilege: administer */ \
    4, /* Cluster: General Commissioning, Command: CommissioningComplete, Privilege: administer */ \
    0, /* Cluster: Groups, Command: AddGroup, Privilege: manage */ \
    3, /* Cluster: Groups, Command: RemoveGroup, Privilege: manage */ \
    4, /* Cluster: Groups, Command: RemoveAllGroups, Privilege: manage */ \
    5, /* Cluster: Groups, Command: AddGroupIfIdentifying, Privilege: manage */ \
    0, /* Cluster: Identify, Command: Identify, Privilege: manage */ \
    0, /* Cluster: Network Commissioning, Command: ScanNetworks, Privilege: administer */ \
    2, /* Cluster: Network Commissioning, Command: AddOrUpdateWiFiNetwork, Privilege: administer */ \
    3, /* Cluster: Network Commissioning, Command: AddOrUpdateThreadNetwork, Privilege: administer */ \
    4, /* Cluster: Network Commissioning, Command: RemoveNetwork, Privilege: administer */ \
    6, /* Cluster: Network Commissioning, Command: ConnectNetwork, Privilege: administer */ \
    8, /* Cluster: Network Commissioning, Command: ReorderNetwork, Privilege: administer */ \
    0, /* Cluster: Operational Credentials, Command: AttestationRequest, Privilege: administer */ \
    2, /* Cluster: Operational Credentials, Command: CertificateChainRequest, Privilege: administer */ \
    4, /* Cluster: Operational Credentials, Command: CSRRequest, Privilege: administer */ \
    6, /* Cluster: Operational Credentials, Command: AddNOC, Privilege: administer */ \
    7, /* Cluster: Operational Credentials, Command: UpdateNOC, Privilege: administer */ \
    9, /* Cluster: Operational Credentials, Command: UpdateFabricLabel, Privilege: administer */ \
    10, /* Cluster: Operational Credentials, Command: RemoveFabric, Privilege: administer */ \
    11, /* Cluster: Operational Credentials, Command: AddTrustedRootCertificate, Privilege: administer */ \
    12, /* Cluster: Operational Credentials, Command: RemoveTrustedRootCertificate, Privilege: administer */ \
}

// Parallel array data (cluster, command, *privilege*) for invoke command
#define GENERATED_ACCESS_INVOKE_COMMAND__PRIVILEGE { \
    kMatterAccessPrivilegeAdminister, /* Cluster: AdministratorCommissioning, Command: OpenCommissioningWindow, Privilege: administer */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: AdministratorCommissioning, Command: OpenBasicCommissioningWindow, Privilege: administer */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: AdministratorCommissioning, Command: RevokeCommissioning, Privilege: administer */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: Door Lock, Command: SetWeekDaySchedule, Privilege: administer */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: Door Lock, Command: GetWeekDaySchedule, Privilege: administer */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: Door Lock, Command: ClearWeekDaySchedule, Privilege: administer */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: Door Lock, Command: SetYearDaySchedule, Privilege: administer */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: Door Lock, Command: GetYearDaySchedule, Privilege: administer */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: Door Lock, Command: ClearYearDaySchedule, Privilege: administer */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: Door Lock, Command: SetHolidaySchedule, Privilege: administer */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: Door Lock, Command: GetHolidaySchedule, Privilege: administer */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: Door Lock, Command: ClearHolidaySchedule, Privilege: administer */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: Door Lock, Command: SetUser, Privilege: administer */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: Door Lock, Command: GetUser, Privilege: administer */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: Door Lock, Command: ClearUser, Privilege: administer */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: Door Lock, Command: SetCredential, Privilege: administer */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: Door Lock, Command: GetCredentialStatus, Privilege: administer */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: Door Lock, Command: ClearCredential, Privilege: administer */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: General Commissioning, Command: ArmFailSafe, Privilege: administer */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: General Commissioning, Command: SetRegulatoryConfig, Privilege: administer */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: General Commissioning, Command: CommissioningComplete, Privilege: administer */ \
    kMatterAccessPrivilegeManage, /* Cluster: Groups, Command: AddGroup, Privilege: manage */ \
    kMatterAccessPrivilegeManage, /* Cluster: Groups, Command: RemoveGroup, Privilege: manage */ \
    kMatterAccessPrivilegeManage, /* Cluster: Groups, Command: RemoveAllGroups, Privilege: manage */ \
    kMatterAccessPrivilegeManage, /* Cluster: Groups, Command: AddGroupIfIdentifying, Privilege: manage */ \
    kMatterAccessPrivilegeManage, /* Cluster: Identify, Command: Identify, Privilege: manage */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: Network Commissioning, Command: ScanNetworks, Privilege: administer */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: Network Commissioning, Command: AddOrUpdateWiFiNetwork, Privilege: administer */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: Network Commissioning, Command: AddOrUpdateThreadNetwork, Privilege: administer */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: Network Commissioning, Command: RemoveNetwork, Privilege: administer */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: Network Commissioning, Command: ConnectNetwork, Privilege: administer */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: Network Commissioning, Command: ReorderNetwork, Privilege: administer */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: Operational Credentials, Command: AttestationRequest, Privilege: administer */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: Operational Credentials, Command: CertificateChainRequest, Privilege: administer */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: Operational Credentials, Command: CSRRequest, Privilege: administer */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: Operational Credentials, Command: AddNOC, Privilege: administer */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: Operational Credentials, Command: UpdateNOC, Privilege: administer */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: Operational Credentials, Command: UpdateFabricLabel, Privilege: administer */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: Operational Credentials, Command: RemoveFabric, Privilege: administer */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: Operational Credentials, Command: AddTrustedRootCertificate, Privilege: administer */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: Operational Credentials, Command: RemoveTrustedRootCertificate, Privilege: administer */ \
}

////////////////////////////////////////////////////////////////////////////////

// Parallel array data (*cluster*, event, privilege) for read event
#define GENERATED_ACCESS_READ_EVENT__CLUSTER { \
    31, /* Cluster: Access Control, Event: AccessControlEntryChanged, Privilege: administer */ \
    31, /* Cluster: Access Control, Event: AccessControlExtensionChanged, Privilege: administer */ \
}

// Parallel array data (cluster, *event*, privilege) for read event
#define GENERATED_ACCESS_READ_EVENT__EVENT { \
    0, /* Cluster: Access Control, Event: AccessControlEntryChanged, Privilege: administer */ \
    1, /* Cluster: Access Control, Event: AccessControlExtensionChanged, Privilege: administer */ \
}

// Parallel array data (cluster, event, *privilege*) for read event
#define GENERATED_ACCESS_READ_EVENT__PRIVILEGE { \
    kMatterAccessPrivilegeAdminister, /* Cluster: Access Control, Event: AccessControlEntryChanged, Privilege: administer */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: Access Control, Event: AccessControlExtensionChanged, Privilege: administer */ \
}

////////////////////////////////////////////////////////////////////////////////

// clang-format on
