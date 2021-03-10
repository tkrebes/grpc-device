//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Real implementation of LibraryInterface for NI-SWITCH
//---------------------------------------------------------------------
#ifndef GRPC_NISWITCH_LIBRARY_H
#define GRPC_NISWITCH_LIBRARY_H

#include "niswitch_library_interface.h"

#include <server/shared_library.h>

namespace grpc {
namespace niswitch {

class NiSwitchLibrary : public grpc::niswitch::NiSwitchLibraryInterface {
 public:
  NiSwitchLibrary();
  virtual ~NiSwitchLibrary();

  ::grpc::Status check_function_exists(std::string functionName);
  ViStatus AbortScan(ViSession vi);
  ViStatus CanConnect(ViSession vi, ViConstString channel1, ViConstString channel2, ViInt32* pathCapability);
  ViStatus CheckAttributeViBoolean(ViSession vi, ViConstString channelName, ViAttr attributeId, ViBoolean attributeValue);
  ViStatus CheckAttributeViInt32(ViSession vi, ViConstString channelName, ViAttr attributeId, ViInt32 attributeValue);
  ViStatus CheckAttributeViReal64(ViSession vi, ViConstString channelName, ViAttr attributeId, ViReal64 attributeValue);
  ViStatus CheckAttributeViString(ViSession vi, ViConstString channelName, ViAttr attributeId, ViString attributeValue);
  ViStatus CheckAttributeViSession(ViSession vi, ViConstString channelName, ViAttr attributeId, ViSession attributeValue);
  ViStatus ClearError(ViSession vi);
  ViStatus ClearInterchangeWarnings(ViSession vi);
  ViStatus Commit(ViSession vi);
  ViStatus ConfigureScanList(ViSession vi, ViConstString scanlist, ViInt32 scanMode);
  ViStatus ConfigureScanTrigger(ViSession vi, ViReal64 scanDelay, ViInt32 triggerInput, ViInt32 scanAdvancedOutput);
  ViStatus Connect(ViSession vi, ViConstString channel1, ViConstString channel2);
  ViStatus ConnectMultiple(ViSession vi, ViConstString connectionList);
  ViStatus Disable(ViSession vi);
  ViStatus Disconnect(ViSession vi, ViConstString channel1, ViConstString channel2);
  ViStatus DisconnectAll(ViSession vi);
  ViStatus DisconnectMultiple(ViSession vi, ViConstString disconnectionList);
  ViStatus GetAttributeViBoolean(ViSession vi, ViConstString channelName, ViAttr attributeId, ViBoolean* attributeValue);
  ViStatus GetAttributeViInt32(ViSession vi, ViConstString channelName, ViAttr attributeId, ViInt32* attributeValue);
  ViStatus GetAttributeViReal64(ViSession vi, ViConstString channelName, ViAttr attributeId, ViReal64* attributeValue);
  ViStatus GetAttributeViString(ViSession vi, ViConstString channelName, ViAttr attributeId, ViInt32 arraySize, ViChar attributeValue[]);
  ViStatus GetAttributeViSession(ViSession vi, ViConstString channelName, ViAttr attributeId, ViSession* attributeValue);
  ViStatus GetChannelName(ViSession vi, ViInt32 index, ViInt32 bufferSize, ViChar channelNameBuffer[]);
  ViStatus GetError(ViSession vi, ViStatus* code, ViInt32 bufferSize, ViChar description[]);
  ViStatus GetNextCoercionRecord(ViSession vi, ViInt32 bufferSize, ViChar coercionRecord[]);
  ViStatus GetNextInterchangeWarning(ViSession vi, ViInt32 bufferSize, ViChar interchangeWarning[]);
  ViStatus GetPath(ViSession vi, ViConstString channel1, ViConstString channel2, ViInt32 bufferSize, ViChar path[]);
  ViStatus GetRelayCount(ViSession vi, ViConstString relayName, ViInt32* relayCount);
  ViStatus GetRelayName(ViSession vi, ViInt32 index, ViInt32 relayNameBufferSize, ViChar relayNameBuffer[]);
  ViStatus GetRelayPosition(ViSession vi, ViConstString relayName, ViInt32* relayPosition);
  ViStatus init(ViRsrc resourceName, ViBoolean idQuery, ViBoolean resetDevice, ViSession* vi);
  ViStatus InitWithOptions(ViRsrc resourceName, ViBoolean idQuery, ViBoolean resetDevice, ViConstString optionString, ViSession* vi);
  ViStatus InitWithTopology(ViRsrc resourceName, ViConstString topology, ViBoolean simulate, ViBoolean resetDevice, ViSession* vi);
  ViStatus InitiateScan(ViSession vi);
  ViStatus InvalidateAllAttributes(ViSession vi);
  ViStatus IsDebounced(ViSession vi, ViBoolean* isDebounced);
  ViStatus IsScanning(ViSession vi, ViBoolean* isScanning);
  ViStatus LockSession(ViSession vi, ViBoolean* callerHasLock);
  ViStatus RelayControl(ViSession vi, ViConstString relayName, ViInt32 relayAction);
  ViStatus ResetInterchangeCheck(ViSession vi);
  ViStatus ResetWithDefaults(ViSession vi);
  ViStatus RouteScanAdvancedOutput(ViSession vi, ViInt32 scanAdvancedOutputConnector, ViInt32 scanAdvancedOutputBusLine, ViBoolean invert);
  ViStatus RouteTriggerInput(ViSession vi, ViInt32 triggerInputConnector, ViInt32 triggerInputBusLine, ViBoolean invert);
  ViStatus Scan(ViSession vi, ViConstString scanlist, ViInt16 initiation);
  ViStatus SendSoftwareTrigger(ViSession vi);
  ViStatus SetAttributeViBoolean(ViSession vi, ViConstString channelName, ViAttr attributeId, ViBoolean attributeValue);
  ViStatus SetAttributeViInt32(ViSession vi, ViConstString channelName, ViAttr attributeId, ViInt32 attributeValue);
  ViStatus SetAttributeViReal64(ViSession vi, ViConstString channelName, ViAttr attributeId, ViReal64 attributeValue);
  ViStatus SetAttributeViString(ViSession vi, ViConstString channelName, ViAttr attributeId, ViString attributeValue);
  ViStatus SetAttributeViSession(ViSession vi, ViConstString channelName, ViAttr attributeId, ViSession attributeValue);
  ViStatus SetContinuousScan(ViSession vi, ViBoolean continuousScan);
  ViStatus SetPath(ViSession vi, ViConstString pathList);
  ViStatus UnlockSession(ViSession vi, ViBoolean* callerHasLock);
  ViStatus WaitForDebounce(ViSession vi, ViInt32 maximumTimeMs);
  ViStatus WaitForScanComplete(ViSession vi, ViInt32 maximumTimeMs);
  ViStatus close(ViSession vi);
  ViStatus error_message(ViSession vi, ViStatus errorCode, ViChar errorMessage[256]);
  ViStatus reset(ViSession vi);
  ViStatus self_test(ViSession vi, ViInt16* selfTestResult, ViChar selfTestMessage[256]);
  ViStatus error_query(ViSession vi, ViInt32* errorCode, ViChar errorMessage[256]);
  ViStatus revision_query(ViSession vi, ViChar instrumentDriverRevision[256], ViChar firmwareRevision[256]);

 private:
  using AbortScanPtr = ViStatus (*)(ViSession vi);
  using CanConnectPtr = ViStatus (*)(ViSession vi, ViConstString channel1, ViConstString channel2, ViInt32* pathCapability);
  using CheckAttributeViBooleanPtr = ViStatus (*)(ViSession vi, ViConstString channelName, ViAttr attributeId, ViBoolean attributeValue);
  using CheckAttributeViInt32Ptr = ViStatus (*)(ViSession vi, ViConstString channelName, ViAttr attributeId, ViInt32 attributeValue);
  using CheckAttributeViReal64Ptr = ViStatus (*)(ViSession vi, ViConstString channelName, ViAttr attributeId, ViReal64 attributeValue);
  using CheckAttributeViStringPtr = ViStatus (*)(ViSession vi, ViConstString channelName, ViAttr attributeId, ViString attributeValue);
  using CheckAttributeViSessionPtr = ViStatus (*)(ViSession vi, ViConstString channelName, ViAttr attributeId, ViSession attributeValue);
  using ClearErrorPtr = ViStatus (*)(ViSession vi);
  using ClearInterchangeWarningsPtr = ViStatus (*)(ViSession vi);
  using CommitPtr = ViStatus (*)(ViSession vi);
  using ConfigureScanListPtr = ViStatus (*)(ViSession vi, ViConstString scanlist, ViInt32 scanMode);
  using ConfigureScanTriggerPtr = ViStatus (*)(ViSession vi, ViReal64 scanDelay, ViInt32 triggerInput, ViInt32 scanAdvancedOutput);
  using ConnectPtr = ViStatus (*)(ViSession vi, ViConstString channel1, ViConstString channel2);
  using ConnectMultiplePtr = ViStatus (*)(ViSession vi, ViConstString connectionList);
  using DisablePtr = ViStatus (*)(ViSession vi);
  using DisconnectPtr = ViStatus (*)(ViSession vi, ViConstString channel1, ViConstString channel2);
  using DisconnectAllPtr = ViStatus (*)(ViSession vi);
  using DisconnectMultiplePtr = ViStatus (*)(ViSession vi, ViConstString disconnectionList);
  using GetAttributeViBooleanPtr = ViStatus (*)(ViSession vi, ViConstString channelName, ViAttr attributeId, ViBoolean* attributeValue);
  using GetAttributeViInt32Ptr = ViStatus (*)(ViSession vi, ViConstString channelName, ViAttr attributeId, ViInt32* attributeValue);
  using GetAttributeViReal64Ptr = ViStatus (*)(ViSession vi, ViConstString channelName, ViAttr attributeId, ViReal64* attributeValue);
  using GetAttributeViStringPtr = ViStatus (*)(ViSession vi, ViConstString channelName, ViAttr attributeId, ViInt32 arraySize, ViChar attributeValue[]);
  using GetAttributeViSessionPtr = ViStatus (*)(ViSession vi, ViConstString channelName, ViAttr attributeId, ViSession* attributeValue);
  using GetChannelNamePtr = ViStatus (*)(ViSession vi, ViInt32 index, ViInt32 bufferSize, ViChar channelNameBuffer[]);
  using GetErrorPtr = ViStatus (*)(ViSession vi, ViStatus* code, ViInt32 bufferSize, ViChar description[]);
  using GetNextCoercionRecordPtr = ViStatus (*)(ViSession vi, ViInt32 bufferSize, ViChar coercionRecord[]);
  using GetNextInterchangeWarningPtr = ViStatus (*)(ViSession vi, ViInt32 bufferSize, ViChar interchangeWarning[]);
  using GetPathPtr = ViStatus (*)(ViSession vi, ViConstString channel1, ViConstString channel2, ViInt32 bufferSize, ViChar path[]);
  using GetRelayCountPtr = ViStatus (*)(ViSession vi, ViConstString relayName, ViInt32* relayCount);
  using GetRelayNamePtr = ViStatus (*)(ViSession vi, ViInt32 index, ViInt32 relayNameBufferSize, ViChar relayNameBuffer[]);
  using GetRelayPositionPtr = ViStatus (*)(ViSession vi, ViConstString relayName, ViInt32* relayPosition);
  using initPtr = ViStatus (*)(ViRsrc resourceName, ViBoolean idQuery, ViBoolean resetDevice, ViSession* vi);
  using InitWithOptionsPtr = ViStatus (*)(ViRsrc resourceName, ViBoolean idQuery, ViBoolean resetDevice, ViConstString optionString, ViSession* vi);
  using InitWithTopologyPtr = ViStatus (*)(ViRsrc resourceName, ViConstString topology, ViBoolean simulate, ViBoolean resetDevice, ViSession* vi);
  using InitiateScanPtr = ViStatus (*)(ViSession vi);
  using InvalidateAllAttributesPtr = ViStatus (*)(ViSession vi);
  using IsDebouncedPtr = ViStatus (*)(ViSession vi, ViBoolean* isDebounced);
  using IsScanningPtr = ViStatus (*)(ViSession vi, ViBoolean* isScanning);
  using LockSessionPtr = ViStatus (*)(ViSession vi, ViBoolean* callerHasLock);
  using RelayControlPtr = ViStatus (*)(ViSession vi, ViConstString relayName, ViInt32 relayAction);
  using ResetInterchangeCheckPtr = ViStatus (*)(ViSession vi);
  using ResetWithDefaultsPtr = ViStatus (*)(ViSession vi);
  using RouteScanAdvancedOutputPtr = ViStatus (*)(ViSession vi, ViInt32 scanAdvancedOutputConnector, ViInt32 scanAdvancedOutputBusLine, ViBoolean invert);
  using RouteTriggerInputPtr = ViStatus (*)(ViSession vi, ViInt32 triggerInputConnector, ViInt32 triggerInputBusLine, ViBoolean invert);
  using ScanPtr = ViStatus (*)(ViSession vi, ViConstString scanlist, ViInt16 initiation);
  using SendSoftwareTriggerPtr = ViStatus (*)(ViSession vi);
  using SetAttributeViBooleanPtr = ViStatus (*)(ViSession vi, ViConstString channelName, ViAttr attributeId, ViBoolean attributeValue);
  using SetAttributeViInt32Ptr = ViStatus (*)(ViSession vi, ViConstString channelName, ViAttr attributeId, ViInt32 attributeValue);
  using SetAttributeViReal64Ptr = ViStatus (*)(ViSession vi, ViConstString channelName, ViAttr attributeId, ViReal64 attributeValue);
  using SetAttributeViStringPtr = ViStatus (*)(ViSession vi, ViConstString channelName, ViAttr attributeId, ViString attributeValue);
  using SetAttributeViSessionPtr = ViStatus (*)(ViSession vi, ViConstString channelName, ViAttr attributeId, ViSession attributeValue);
  using SetContinuousScanPtr = ViStatus (*)(ViSession vi, ViBoolean continuousScan);
  using SetPathPtr = ViStatus (*)(ViSession vi, ViConstString pathList);
  using UnlockSessionPtr = ViStatus (*)(ViSession vi, ViBoolean* callerHasLock);
  using WaitForDebouncePtr = ViStatus (*)(ViSession vi, ViInt32 maximumTimeMs);
  using WaitForScanCompletePtr = ViStatus (*)(ViSession vi, ViInt32 maximumTimeMs);
  using closePtr = ViStatus (*)(ViSession vi);
  using error_messagePtr = ViStatus (*)(ViSession vi, ViStatus errorCode, ViChar errorMessage[256]);
  using resetPtr = ViStatus (*)(ViSession vi);
  using self_testPtr = ViStatus (*)(ViSession vi, ViInt16* selfTestResult, ViChar selfTestMessage[256]);
  using error_queryPtr = ViStatus (*)(ViSession vi, ViInt32* errorCode, ViChar errorMessage[256]);
  using revision_queryPtr = ViStatus (*)(ViSession vi, ViChar instrumentDriverRevision[256], ViChar firmwareRevision[256]);

  typedef struct FunctionPointers {
    AbortScanPtr AbortScan;
    CanConnectPtr CanConnect;
    CheckAttributeViBooleanPtr CheckAttributeViBoolean;
    CheckAttributeViInt32Ptr CheckAttributeViInt32;
    CheckAttributeViReal64Ptr CheckAttributeViReal64;
    CheckAttributeViStringPtr CheckAttributeViString;
    CheckAttributeViSessionPtr CheckAttributeViSession;
    ClearErrorPtr ClearError;
    ClearInterchangeWarningsPtr ClearInterchangeWarnings;
    CommitPtr Commit;
    ConfigureScanListPtr ConfigureScanList;
    ConfigureScanTriggerPtr ConfigureScanTrigger;
    ConnectPtr Connect;
    ConnectMultiplePtr ConnectMultiple;
    DisablePtr Disable;
    DisconnectPtr Disconnect;
    DisconnectAllPtr DisconnectAll;
    DisconnectMultiplePtr DisconnectMultiple;
    GetAttributeViBooleanPtr GetAttributeViBoolean;
    GetAttributeViInt32Ptr GetAttributeViInt32;
    GetAttributeViReal64Ptr GetAttributeViReal64;
    GetAttributeViStringPtr GetAttributeViString;
    GetAttributeViSessionPtr GetAttributeViSession;
    GetChannelNamePtr GetChannelName;
    GetErrorPtr GetError;
    GetNextCoercionRecordPtr GetNextCoercionRecord;
    GetNextInterchangeWarningPtr GetNextInterchangeWarning;
    GetPathPtr GetPath;
    GetRelayCountPtr GetRelayCount;
    GetRelayNamePtr GetRelayName;
    GetRelayPositionPtr GetRelayPosition;
    initPtr init;
    InitWithOptionsPtr InitWithOptions;
    InitWithTopologyPtr InitWithTopology;
    InitiateScanPtr InitiateScan;
    InvalidateAllAttributesPtr InvalidateAllAttributes;
    IsDebouncedPtr IsDebounced;
    IsScanningPtr IsScanning;
    LockSessionPtr LockSession;
    RelayControlPtr RelayControl;
    ResetInterchangeCheckPtr ResetInterchangeCheck;
    ResetWithDefaultsPtr ResetWithDefaults;
    RouteScanAdvancedOutputPtr RouteScanAdvancedOutput;
    RouteTriggerInputPtr RouteTriggerInput;
    ScanPtr Scan;
    SendSoftwareTriggerPtr SendSoftwareTrigger;
    SetAttributeViBooleanPtr SetAttributeViBoolean;
    SetAttributeViInt32Ptr SetAttributeViInt32;
    SetAttributeViReal64Ptr SetAttributeViReal64;
    SetAttributeViStringPtr SetAttributeViString;
    SetAttributeViSessionPtr SetAttributeViSession;
    SetContinuousScanPtr SetContinuousScan;
    SetPathPtr SetPath;
    UnlockSessionPtr UnlockSession;
    WaitForDebouncePtr WaitForDebounce;
    WaitForScanCompletePtr WaitForScanComplete;
    closePtr close;
    error_messagePtr error_message;
    resetPtr reset;
    self_testPtr self_test;
    error_queryPtr error_query;
    revision_queryPtr revision_query;
  } FunctionLoadStatus;

  grpc::nidevice::SharedLibrary shared_library_;
  FunctionPointers function_pointers_;
};

}  // namespace niswitch
}  // namespace grpc

#endif  // GRPC_NISWITCH_LIBRARY_H
