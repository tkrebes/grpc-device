#ifndef NI_HARDWARE_GRPC_INTERNAL_DEVICEENUMERATORFAKELIBRARY_H
#define NI_HARDWARE_GRPC_INTERNAL_DEVICEENUMERATORFAKELIBRARY_H

#include <nisyscfg.h>

#include "device_enumerator_interface.h"

namespace ni {
namespace hardware {
namespace grpc {
namespace internal {

class DeviceEnumeratorFakeLibrary : public DeviceEnumeratorInterface {
 public:
  ::grpc::Status check_syscfg_library_exists() override;
  NISysCfgStatus find_hardware() override;
  NISysCfgStatus next_resource(NISysCfgResourceHandle* resourceHandle) override;
  NISysCfgStatus get_resource_property(NISysCfgEnumResourceHandle resourceEnumHandle, void* value) override;
  NISysCfgStatus close_handle(void* sysCfgHandle) override;

 private:
  struct Resource {
    std::string name;
    Resource(std::string name)
    {
      this->name = name;
    }
  };
  typedef Resource* r_handle;

  std::vector<Resource> resources{};
  std::vector<Resource>::iterator it;
};

}  // namespace internal
}  // namespace grpc
}  // namespace hardware
}  // namespace ni

#endif  // NI_HARDWARE_GRPC_INTERNAL_DEVICEENUMERATORFAKELIBRARY_H
