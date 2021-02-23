#include "device_enumerator_new.h"

namespace ni {
namespace hardware {
namespace grpc {
namespace internal {

DeviceEnumeratorNew::DeviceEnumeratorNew(DeviceEnumeratorInterface* library)
    : library_(library)
{
}

// Provides a list of devices or chassis connected to server under localhost. This internally uses the
// "NI System Configuration API". If it is not currently installed, it can be downloaded from this page:
// https://www.ni.com/en-in/support/downloads/drivers/download.system-configuration.html.
::grpc::Status DeviceEnumeratorNew::enumerate_devices(google::protobuf::RepeatedPtrField<DeviceProperties>* devices)
{
  ::grpc::Status library_status = library_->check_syscfg_library_exists();
  if (!library_status.ok()) {
    return library_status;
  }

  NISysCfgStatus status = get_list_of_devices(devices);
  if (NISysCfg_Failed(status)) {
    return ::grpc::Status(::grpc::StatusCode::INTERNAL, "The NI System Configuration API was unable to enumerate the devices.");
  }

  return ::grpc::Status::OK;
}

NISysCfgStatus DeviceEnumeratorNew::get_list_of_devices(google::protobuf::RepeatedPtrField<DeviceProperties>* devices)
{
  NISysCfgStatus status = NISysCfg_OK;
  NISysCfgResourceHandle resource = NULL;
  char name[NISYSCFG_SIMPLE_STRING_LENGTH] = "";

  if (NISysCfg_Succeeded(status = library_->find_hardware())) {
    while (NISysCfg_Succeeded(status) && (status = library_->next_resource(&resource)) == NISysCfg_OK) {
      DeviceProperties* properties = devices->Add();
      library_->get_resource_property(resource, name);
      properties->set_name(name);
      library_->close_handle(resource);
    }
  }
  
  return status;
}

}  // namespace internal
}  // namespace grpc
}  // namespace hardware
}  // namespace ni
