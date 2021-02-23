#ifndef NI_HARDWARE_GRPC_INTERNAL_DEVICEENUMERATOR
#define NI_HARDWARE_GRPC_INTERNAL_DEVICEENUMERATOR

#include <grpcpp/grpcpp.h>
#include <nisyscfg.h>

#include "device_enumerator_interface.h"
#include "session_repository.h"
#include "shared_library.h"

namespace ni {
namespace hardware {
namespace grpc {
namespace internal {

class DeviceEnumeratorNew {
 public:
  DeviceEnumeratorNew(DeviceEnumeratorInterface* library);

  ::grpc::Status enumerate_devices(google::protobuf::RepeatedPtrField<DeviceProperties>* devices);

 private:
  struct Resource {
    std::string name;
    Resource(std::string name)
    {
      this->name = name;
    }
  };
  typedef Resource* r_handle;

  NISysCfgStatus get_list_of_devices(google::protobuf::RepeatedPtrField<DeviceProperties>* devices);

  internal::DeviceEnumeratorInterface* library_;
};

}  // namespace internal
}  // namespace grpc
}  // namespace hardware
}  // namespace ni

#endif  // NI_HARDWARE_GRPC_INTERNAL_DEVICEMANAGEMENT
