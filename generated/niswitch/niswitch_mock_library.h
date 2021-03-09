//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Mock of LibraryInterface for NI-SWITCH
//---------------------------------------------------------------------
#ifndef NI_NISWITCH_GRPC_MOCK_LIBRARY_H
#define NI_NISWITCH_GRPC_MOCK_LIBRARY_H

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "niswitch_library_interface.h"

namespace ni {
namespace tests {
namespace unit {

class NiSwitchMockLibrary : public ni::niswitch::grpc::NiSwitchLibraryInterface {
 public:
  MOCK_METHOD(ViStatus, AbortScan, (ViSession vi), (override));
  MOCK_METHOD(ViStatus, CanConnect, (ViSession vi, ViConstString channel1, ViConstString channel2, ViInt32* pathCapability), (override));
  MOCK_METHOD(ViStatus, CheckAttributeViBoolean, (ViSession vi, ViConstString channelName, ViAttr attributeId, ViBoolean attributeValue), (override));
  MOCK_METHOD(ViStatus, CheckAttributeViInt32, (ViSession vi, ViConstString channelName, ViAttr attributeId, ViInt32 attributeValue), (override));
  MOCK_METHOD(ViStatus, CheckAttributeViReal64, (ViSession vi, ViConstString channelName, ViAttr attributeId, ViReal64 attributeValue), (override));
  MOCK_METHOD(ViStatus, CheckAttributeViString, (ViSession vi, ViConstString channelName, ViAttr attributeId, ViString attributeValue), (override));
  MOCK_METHOD(ViStatus, CheckAttributeViSession, (ViSession vi, ViConstString channelName, ViAttr attributeId, ViSession attributeValue), (override));
  MOCK_METHOD(ViStatus, ClearError, (ViSession vi), (override));
  MOCK_METHOD(ViStatus, ClearInterchangeWarnings, (ViSession vi), (override));
  MOCK_METHOD(ViStatus, Commit, (ViSession vi), (override));
  MOCK_METHOD(ViStatus, ConfigureScanList, (ViSession vi, ViConstString scanlist, ViInt32 scanMode), (override));
  MOCK_METHOD(ViStatus, ConfigureScanTrigger, (ViSession vi, ViReal64 scanDelay, ViInt32 triggerInput, ViInt32 scanAdvancedOutput), (override));
  MOCK_METHOD(ViStatus, Connect, (ViSession vi, ViConstString channel1, ViConstString channel2), (override));
  MOCK_METHOD(ViStatus, ConnectMultiple, (ViSession vi, ViConstString connectionList), (override));
  MOCK_METHOD(ViStatus, Disable, (ViSession vi), (override));
  MOCK_METHOD(ViStatus, Disconnect, (ViSession vi, ViConstString channel1, ViConstString channel2), (override));
  MOCK_METHOD(ViStatus, DisconnectAll, (ViSession vi), (override));
  MOCK_METHOD(ViStatus, DisconnectMultiple, (ViSession vi, ViConstString disconnectionList), (override));
  MOCK_METHOD(ViStatus, GetAttributeViBoolean, (ViSession vi, ViConstString channelName, ViAttr attributeId, ViBoolean* attributeValue), (override));
  MOCK_METHOD(ViStatus, GetAttributeViInt32, (ViSession vi, ViConstString channelName, ViAttr attributeId, ViInt32* attributeValue), (override));
  MOCK_METHOD(ViStatus, GetAttributeViReal64, (ViSession vi, ViConstString channelName, ViAttr attributeId, ViReal64* attributeValue), (override));
  MOCK_METHOD(ViStatus, GetAttributeViString, (ViSession vi, ViConstString channelName, ViAttr attributeId, ViInt32 arraySize, ViChar attributeValue[]), (override));
  MOCK_METHOD(ViStatus, GetAttributeViSession, (ViSession vi, ViConstString channelName, ViAttr attributeId, ViSession* attributeValue), (override));
  MOCK_METHOD(ViStatus, GetChannelName, (ViSession vi, ViInt32 index, ViInt32 bufferSize, ViChar channelNameBuffer[]), (override));
  MOCK_METHOD(ViStatus, GetError, (ViSession vi, ViStatus* code, ViInt32 bufferSize, ViChar description[]), (override));
  MOCK_METHOD(ViStatus, GetNextCoercionRecord, (ViSession vi, ViInt32 bufferSize, ViChar coercionRecord[]), (override));
  MOCK_METHOD(ViStatus, GetNextInterchangeWarning, (ViSession vi, ViInt32 bufferSize, ViChar interchangeWarning[]), (override));
  MOCK_METHOD(ViStatus, GetPath, (ViSession vi, ViConstString channel1, ViConstString channel2, ViInt32 bufferSize, ViChar path[]), (override));
  MOCK_METHOD(ViStatus, GetRelayCount, (ViSession vi, ViConstString relayName, ViInt32* relayCount), (override));
  MOCK_METHOD(ViStatus, GetRelayName, (ViSession vi, ViInt32 index, ViInt32 relayNameBufferSize, ViChar relayNameBuffer[]), (override));
  MOCK_METHOD(ViStatus, GetRelayPosition, (ViSession vi, ViConstString relayName, ViInt32* relayPosition), (override));
  MOCK_METHOD(ViStatus, init, (ViRsrc resourceName, ViBoolean idQuery, ViBoolean resetDevice, ViSession* vi), (override));
  MOCK_METHOD(ViStatus, InitWithOptions, (ViRsrc resourceName, ViBoolean idQuery, ViBoolean resetDevice, ViConstString optionString, ViSession* vi), (override));
  MOCK_METHOD(ViStatus, InitWithTopology, (ViRsrc resourceName, ViConstString topology, ViBoolean simulate, ViBoolean resetDevice, ViSession* vi), (override));
  MOCK_METHOD(ViStatus, InitiateScan, (ViSession vi), (override));
  MOCK_METHOD(ViStatus, InvalidateAllAttributes, (ViSession vi), (override));
  MOCK_METHOD(ViStatus, IsDebounced, (ViSession vi, ViBoolean* isDebounced), (override));
  MOCK_METHOD(ViStatus, IsScanning, (ViSession vi, ViBoolean* isScanning), (override));
  MOCK_METHOD(ViStatus, LockSession, (ViSession vi, ViBoolean* callerHasLock), (override));
  MOCK_METHOD(ViStatus, RelayControl, (ViSession vi, ViConstString relayName, ViInt32 relayAction), (override));
  MOCK_METHOD(ViStatus, ResetInterchangeCheck, (ViSession vi), (override));
  MOCK_METHOD(ViStatus, ResetWithDefaults, (ViSession vi), (override));
  MOCK_METHOD(ViStatus, RouteScanAdvancedOutput, (ViSession vi, ViInt32 scanAdvancedOutputConnector, ViInt32 scanAdvancedOutputBusLine, ViBoolean invert), (override));
  MOCK_METHOD(ViStatus, RouteTriggerInput, (ViSession vi, ViInt32 triggerInputConnector, ViInt32 triggerInputBusLine, ViBoolean invert), (override));
  MOCK_METHOD(ViStatus, Scan, (ViSession vi, ViConstString scanlist, ViInt16 initiation), (override));
  MOCK_METHOD(ViStatus, SendSoftwareTrigger, (ViSession vi), (override));
  MOCK_METHOD(ViStatus, SetAttributeViBoolean, (ViSession vi, ViConstString channelName, ViAttr attributeId, ViBoolean attributeValue), (override));
  MOCK_METHOD(ViStatus, SetAttributeViInt32, (ViSession vi, ViConstString channelName, ViAttr attributeId, ViInt32 attributeValue), (override));
  MOCK_METHOD(ViStatus, SetAttributeViReal64, (ViSession vi, ViConstString channelName, ViAttr attributeId, ViReal64 attributeValue), (override));
  MOCK_METHOD(ViStatus, SetAttributeViString, (ViSession vi, ViConstString channelName, ViAttr attributeId, ViString attributeValue), (override));
  MOCK_METHOD(ViStatus, SetAttributeViSession, (ViSession vi, ViConstString channelName, ViAttr attributeId, ViSession attributeValue), (override));
  MOCK_METHOD(ViStatus, SetContinuousScan, (ViSession vi, ViBoolean continuousScan), (override));
  MOCK_METHOD(ViStatus, SetPath, (ViSession vi, ViConstString pathList), (override));
  MOCK_METHOD(ViStatus, UnlockSession, (ViSession vi, ViBoolean* callerHasLock), (override));
  MOCK_METHOD(ViStatus, WaitForDebounce, (ViSession vi, ViInt32 maximumTimeMs), (override));
  MOCK_METHOD(ViStatus, WaitForScanComplete, (ViSession vi, ViInt32 maximumTimeMs), (override));
  MOCK_METHOD(ViStatus, close, (ViSession vi), (override));
  MOCK_METHOD(ViStatus, error_message, (ViSession vi, ViStatus errorCode, ViChar errorMessage[256]), (override));
  MOCK_METHOD(ViStatus, reset, (ViSession vi), (override));
  MOCK_METHOD(ViStatus, self_test, (ViSession vi, ViInt16* selfTestResult, ViChar selfTestMessage[256]), (override));
  MOCK_METHOD(ViStatus, error_query, (ViSession vi, ViInt32* errorCode, ViChar errorMessage[256]), (override));
  MOCK_METHOD(ViStatus, revision_query, (ViSession vi, ViChar instrumentDriverRevision[256], ViChar firmwareRevision[256]), (override));
};

}  // namespace unit
}  // namespace tests
}  // namespace ni
#endif  // NI_NISWITCH_GRPC_MOCK_LIBRARY_H
