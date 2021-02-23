#ifndef NI_HARDWARE_GRPC_INTERNAL_DEVICEENUMERATORINTERFACE_H
#define NI_HARDWARE_GRPC_INTERNAL_DEVICEENUMERATORINTERFACE_H

#include <grpcpp/grpcpp.h>
#include <nisyscfg.h>

namespace ni {
namespace hardware {
namespace grpc {
namespace internal {

class DeviceEnumeratorInterface {
 public:
  virtual ~DeviceEnumeratorInterface() {}

  virtual ::grpc::Status check_syscfg_library_exists() = 0;
  virtual NISysCfgStatus find_hardware() = 0;
  virtual NISysCfgStatus next_resource(NISysCfgResourceHandle* resourceHandle) = 0;
  virtual NISysCfgStatus get_resource_property(NISysCfgEnumResourceHandle resourceEnumHandle, void* value) = 0;
  virtual NISysCfgStatus close_handle(void* syscfgHandle) = 0;
};

}  // namespace internal
}  // namespace grpc
}  // namespace hardware
}  // namespace ni

#endif  // NI_HARDWARE_GRPC_INTERNAL_DEVICEENUMERATORINTERFACE_H
