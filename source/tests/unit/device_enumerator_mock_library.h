#ifndef NI_TESTS_UNIT_DEVICEENUMERATORMOCKLIBRARY_H
#define NI_TESTS_UNIT_DEVICEENUMERATORMOCKLIBRARY_H

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <nisyscfg.h>

#include "core_server/hardware/grpc/internal/device_enumerator_fake_library.h"

namespace ni {
namespace tests {
namespace unit {

class DeviceEnumeratorMockLibrary : public ni::hardware::grpc::internal::DeviceEnumeratorInterface {
 public:
  MOCK_METHOD(::grpc::Status, check_syscfg_library_exists, (), (override));
  MOCK_METHOD(NISysCfgStatus, find_hardware, (), (override));
  MOCK_METHOD(NISysCfgStatus, next_resource, (NISysCfgResourceHandle * resourceHandle), (override));
  MOCK_METHOD(NISysCfgStatus, get_resource_property, (NISysCfgEnumResourceHandle resourceEnumHandle, void* value), (override));
  MOCK_METHOD(NISysCfgStatus, close_handle, (void* sysCfgHandle), (override));

  void DelegateToFake()
  {
    ON_CALL(*this, check_syscfg_library_exists).WillByDefault([this]() {
      return fake_library_.check_syscfg_library_exists();
    });
    ON_CALL(*this, find_hardware).WillByDefault([this]() {
      return fake_library_.find_hardware();
    });
    ON_CALL(*this, next_resource).WillByDefault([this](NISysCfgResourceHandle* resourceHandle) {
      return fake_library_.next_resource(resourceHandle);
    });
    ON_CALL(*this, get_resource_property).WillByDefault([this](NISysCfgEnumResourceHandle resourceEnumHandle, void* value) {
      return fake_library_.get_resource_property(resourceEnumHandle, value);
    });
    ON_CALL(*this, close_handle).WillByDefault([this](void* sysCfgHandle) {
      return fake_library_.close_handle(sysCfgHandle);
    });
  }

 private:
  ni::hardware::grpc::internal::DeviceEnumeratorFakeLibrary fake_library_;
};

}  // namespace unit
}  // namespace tests
}  // namespace ni

#endif  // NI_TESTS_UNIT_DEVICEENUMERATORMOCKLIBRARY_H
