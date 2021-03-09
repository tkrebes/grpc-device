
//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Service header for the NI-SWITCH Metadata
//---------------------------------------------------------------------
#ifndef NI_NISWITCH_GRPC_SERVICE_H
#define NI_NISWITCH_GRPC_SERVICE_H

#include <niswitch.grpc.pb.h>
#include <condition_variable>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <map>
#include <server/session_repository.h>
#include <server/shared_library.h>

#include "niswitch_library_interface.h"

namespace ni {
namespace niswitch {
namespace grpc {

class NiSwitchService final : public NiSwitch::Service {
public:
  NiSwitchService(NiSwitchLibraryInterface* library, ni::hardware::grpc::internal::SessionRepository* session_repository);
  virtual ~NiSwitchService();
  ::grpc::Status AbortScan(::grpc::ServerContext* context, const AbortScanRequest* request, AbortScanResponse* response) override;
  ::grpc::Status CanConnect(::grpc::ServerContext* context, const CanConnectRequest* request, CanConnectResponse* response) override;
  ::grpc::Status CheckAttributeViBoolean(::grpc::ServerContext* context, const CheckAttributeViBooleanRequest* request, CheckAttributeViBooleanResponse* response) override;
  ::grpc::Status CheckAttributeViInt32(::grpc::ServerContext* context, const CheckAttributeViInt32Request* request, CheckAttributeViInt32Response* response) override;
  ::grpc::Status CheckAttributeViReal64(::grpc::ServerContext* context, const CheckAttributeViReal64Request* request, CheckAttributeViReal64Response* response) override;
  ::grpc::Status CheckAttributeViString(::grpc::ServerContext* context, const CheckAttributeViStringRequest* request, CheckAttributeViStringResponse* response) override;
  ::grpc::Status CheckAttributeViSession(::grpc::ServerContext* context, const CheckAttributeViSessionRequest* request, CheckAttributeViSessionResponse* response) override;
  ::grpc::Status ClearError(::grpc::ServerContext* context, const ClearErrorRequest* request, ClearErrorResponse* response) override;
  ::grpc::Status ClearInterchangeWarnings(::grpc::ServerContext* context, const ClearInterchangeWarningsRequest* request, ClearInterchangeWarningsResponse* response) override;
  ::grpc::Status Commit(::grpc::ServerContext* context, const CommitRequest* request, CommitResponse* response) override;
  ::grpc::Status ConfigureScanList(::grpc::ServerContext* context, const ConfigureScanListRequest* request, ConfigureScanListResponse* response) override;
  ::grpc::Status ConfigureScanTrigger(::grpc::ServerContext* context, const ConfigureScanTriggerRequest* request, ConfigureScanTriggerResponse* response) override;
  ::grpc::Status Connect(::grpc::ServerContext* context, const ConnectRequest* request, ConnectResponse* response) override;
  ::grpc::Status ConnectMultiple(::grpc::ServerContext* context, const ConnectMultipleRequest* request, ConnectMultipleResponse* response) override;
  ::grpc::Status Disable(::grpc::ServerContext* context, const DisableRequest* request, DisableResponse* response) override;
  ::grpc::Status Disconnect(::grpc::ServerContext* context, const DisconnectRequest* request, DisconnectResponse* response) override;
  ::grpc::Status DisconnectAll(::grpc::ServerContext* context, const DisconnectAllRequest* request, DisconnectAllResponse* response) override;
  ::grpc::Status DisconnectMultiple(::grpc::ServerContext* context, const DisconnectMultipleRequest* request, DisconnectMultipleResponse* response) override;
  ::grpc::Status GetAttributeViBoolean(::grpc::ServerContext* context, const GetAttributeViBooleanRequest* request, GetAttributeViBooleanResponse* response) override;
  ::grpc::Status GetAttributeViInt32(::grpc::ServerContext* context, const GetAttributeViInt32Request* request, GetAttributeViInt32Response* response) override;
  ::grpc::Status GetAttributeViReal64(::grpc::ServerContext* context, const GetAttributeViReal64Request* request, GetAttributeViReal64Response* response) override;
  ::grpc::Status GetAttributeViString(::grpc::ServerContext* context, const GetAttributeViStringRequest* request, GetAttributeViStringResponse* response) override;
  ::grpc::Status GetAttributeViSession(::grpc::ServerContext* context, const GetAttributeViSessionRequest* request, GetAttributeViSessionResponse* response) override;
  ::grpc::Status GetChannelName(::grpc::ServerContext* context, const GetChannelNameRequest* request, GetChannelNameResponse* response) override;
  ::grpc::Status GetError(::grpc::ServerContext* context, const GetErrorRequest* request, GetErrorResponse* response) override;
  ::grpc::Status GetNextCoercionRecord(::grpc::ServerContext* context, const GetNextCoercionRecordRequest* request, GetNextCoercionRecordResponse* response) override;
  ::grpc::Status GetNextInterchangeWarning(::grpc::ServerContext* context, const GetNextInterchangeWarningRequest* request, GetNextInterchangeWarningResponse* response) override;
  ::grpc::Status GetPath(::grpc::ServerContext* context, const GetPathRequest* request, GetPathResponse* response) override;
  ::grpc::Status GetRelayCount(::grpc::ServerContext* context, const GetRelayCountRequest* request, GetRelayCountResponse* response) override;
  ::grpc::Status GetRelayName(::grpc::ServerContext* context, const GetRelayNameRequest* request, GetRelayNameResponse* response) override;
  ::grpc::Status GetRelayPosition(::grpc::ServerContext* context, const GetRelayPositionRequest* request, GetRelayPositionResponse* response) override;
  ::grpc::Status Init(::grpc::ServerContext* context, const InitRequest* request, InitResponse* response) override;
  ::grpc::Status InitWithOptions(::grpc::ServerContext* context, const InitWithOptionsRequest* request, InitWithOptionsResponse* response) override;
  ::grpc::Status InitWithTopology(::grpc::ServerContext* context, const InitWithTopologyRequest* request, InitWithTopologyResponse* response) override;
  ::grpc::Status InitiateScan(::grpc::ServerContext* context, const InitiateScanRequest* request, InitiateScanResponse* response) override;
  ::grpc::Status InvalidateAllAttributes(::grpc::ServerContext* context, const InvalidateAllAttributesRequest* request, InvalidateAllAttributesResponse* response) override;
  ::grpc::Status IsDebounced(::grpc::ServerContext* context, const IsDebouncedRequest* request, IsDebouncedResponse* response) override;
  ::grpc::Status IsScanning(::grpc::ServerContext* context, const IsScanningRequest* request, IsScanningResponse* response) override;
  ::grpc::Status LockSession(::grpc::ServerContext* context, const LockSessionRequest* request, LockSessionResponse* response) override;
  ::grpc::Status RelayControl(::grpc::ServerContext* context, const RelayControlRequest* request, RelayControlResponse* response) override;
  ::grpc::Status ResetInterchangeCheck(::grpc::ServerContext* context, const ResetInterchangeCheckRequest* request, ResetInterchangeCheckResponse* response) override;
  ::grpc::Status ResetWithDefaults(::grpc::ServerContext* context, const ResetWithDefaultsRequest* request, ResetWithDefaultsResponse* response) override;
  ::grpc::Status RouteScanAdvancedOutput(::grpc::ServerContext* context, const RouteScanAdvancedOutputRequest* request, RouteScanAdvancedOutputResponse* response) override;
  ::grpc::Status RouteTriggerInput(::grpc::ServerContext* context, const RouteTriggerInputRequest* request, RouteTriggerInputResponse* response) override;
  ::grpc::Status Scan(::grpc::ServerContext* context, const ScanRequest* request, ScanResponse* response) override;
  ::grpc::Status SendSoftwareTrigger(::grpc::ServerContext* context, const SendSoftwareTriggerRequest* request, SendSoftwareTriggerResponse* response) override;
  ::grpc::Status SetAttributeViBoolean(::grpc::ServerContext* context, const SetAttributeViBooleanRequest* request, SetAttributeViBooleanResponse* response) override;
  ::grpc::Status SetAttributeViInt32(::grpc::ServerContext* context, const SetAttributeViInt32Request* request, SetAttributeViInt32Response* response) override;
  ::grpc::Status SetAttributeViReal64(::grpc::ServerContext* context, const SetAttributeViReal64Request* request, SetAttributeViReal64Response* response) override;
  ::grpc::Status SetAttributeViString(::grpc::ServerContext* context, const SetAttributeViStringRequest* request, SetAttributeViStringResponse* response) override;
  ::grpc::Status SetAttributeViSession(::grpc::ServerContext* context, const SetAttributeViSessionRequest* request, SetAttributeViSessionResponse* response) override;
  ::grpc::Status SetContinuousScan(::grpc::ServerContext* context, const SetContinuousScanRequest* request, SetContinuousScanResponse* response) override;
  ::grpc::Status SetPath(::grpc::ServerContext* context, const SetPathRequest* request, SetPathResponse* response) override;
  ::grpc::Status UnlockSession(::grpc::ServerContext* context, const UnlockSessionRequest* request, UnlockSessionResponse* response) override;
  ::grpc::Status WaitForDebounce(::grpc::ServerContext* context, const WaitForDebounceRequest* request, WaitForDebounceResponse* response) override;
  ::grpc::Status WaitForScanComplete(::grpc::ServerContext* context, const WaitForScanCompleteRequest* request, WaitForScanCompleteResponse* response) override;
  ::grpc::Status Close(::grpc::ServerContext* context, const CloseRequest* request, CloseResponse* response) override;
  ::grpc::Status ErrorMessage(::grpc::ServerContext* context, const ErrorMessageRequest* request, ErrorMessageResponse* response) override;
  ::grpc::Status Reset(::grpc::ServerContext* context, const ResetRequest* request, ResetResponse* response) override;
  ::grpc::Status SelfTest(::grpc::ServerContext* context, const SelfTestRequest* request, SelfTestResponse* response) override;
  ::grpc::Status ErrorQuery(::grpc::ServerContext* context, const ErrorQueryRequest* request, ErrorQueryResponse* response) override;
  ::grpc::Status RevisionQuery(::grpc::ServerContext* context, const RevisionQueryRequest* request, RevisionQueryResponse* response) override;
private:
  NiSwitchLibraryInterface* library_;
  ni::hardware::grpc::internal::SessionRepository* session_repository_;
};

} // namespace grpc
} // namespace niswitch
} // namespace ni
#endif  // NI_NISWITCH_GRPC_SERVICE_H
