#include <gtest/gtest.h>

#include "core_server/hardware/grpc/internal/device_enumerator.h"
#include "core_server/hardware/grpc/internal/device_enumerator_new.h"
#include "core_server/hardware/grpc/internal/device_enumerator_fake_library.h"
#include "device_enumerator_mock_library.h"

namespace ni {
namespace tests {
namespace unit {

#if defined(_MSC_VER)
static const char* kSysCfgApiLibraryName = "nisyscfg.dll";
static const char* kFakeSysCfgApiLibraryName = "FakeSysCfgApi.dll";
#else
static const char* kSysCfgApiLibraryName = "libnisyscfg.so";
static const char* kFakeSysCfgApiLibraryName = "FakeSysCfgApi.so";
#endif

TEST(DeviceEnumeratorTests, CreateDeviceEnumerator_SharedLibraryNameIsSetToSysCfgLibrary)
{
  ni::hardware::grpc::internal::DeviceEnumerator device_management;
  std::string shared_library_name = device_management.get_syscfg_library_name();

  EXPECT_STREQ(kSysCfgApiLibraryName, shared_library_name.c_str());
}

TEST(DeviceEnumeratorTests, CreateDeviceEnumeratorWithFakeLibraryName_SharedLibraryNameIsSetToFakeLibrary)
{
  ni::hardware::grpc::internal::DeviceEnumerator device_management(kFakeSysCfgApiLibraryName);
  std::string shared_library_name = device_management.get_syscfg_library_name();

  EXPECT_STREQ(kFakeSysCfgApiLibraryName, shared_library_name.c_str());
}

TEST(DeviceEnumeratorTests, CreateDeviceEnumerator_SharedLibraryIsNotLoaded)
{
  ni::hardware::grpc::internal::DeviceEnumerator device_management;

  EXPECT_FALSE(device_management.is_syscfg_library_loaded());
}

TEST(DeviceEnumeratorTests, CreateDeviceEnumeratorWithMockLibrary_SysCfgLibraryDoesNotExist_DoesNotCallSysCfgFunction)
{
  DeviceEnumeratorMockLibrary mock_library;
  ni::hardware::grpc::internal::DeviceEnumeratorNew device_enumerator(&mock_library);
  google::protobuf::RepeatedPtrField<ni::hardware::grpc::DeviceProperties> devices;
  mock_library.DelegateToFake();
  EXPECT_CALL(mock_library, check_syscfg_library_exists())
      .WillOnce(testing::Return(::grpc::Status(::grpc::NOT_FOUND, "The NI System Configuration library was not found")));
  EXPECT_CALL(mock_library, find_hardware)
      .Times(0);

  ::grpc::Status status = device_enumerator.enumerate_devices(&devices);

  EXPECT_EQ(::grpc::StatusCode::NOT_FOUND, status.error_code());
}

TEST(DeviceEnumeratorTests, CreateDeviceEnumeratorWithMockLibrary_SysCfgLibraryExists_CallsSysCfgFunction)
{
  DeviceEnumeratorMockLibrary mock_library;
  ni::hardware::grpc::internal::DeviceEnumeratorNew device_enumerator(&mock_library);
  google::protobuf::RepeatedPtrField<ni::hardware::grpc::DeviceProperties> devices;
  mock_library.DelegateToFake();
  EXPECT_CALL(mock_library, check_syscfg_library_exists())
      .WillOnce(testing::Return(::grpc::Status(::grpc::NOT_FOUND, "The NI System Configuration library was not found")));
  EXPECT_CALL(mock_library, find_hardware)
      .Times(0);

  ::grpc::Status status = device_enumerator.enumerate_devices(&devices);

  EXPECT_EQ(::grpc::StatusCode::NOT_FOUND, status.error_code());
}

TEST(DeviceEnumeratorTests, CreateDeviceEnumeratorWithMockLibrary_CallEnumerateDevices_ReturnsGrpcOkStatus)
{
  DeviceEnumeratorMockLibrary mock_library;
  ni::hardware::grpc::internal::DeviceEnumeratorNew device_enumerator(&mock_library);
  google::protobuf::RepeatedPtrField<ni::hardware::grpc::DeviceProperties> devices;
  mock_library.DelegateToFake();

  ::grpc::Status status = device_enumerator.enumerate_devices(&devices);

  EXPECT_EQ(::grpc::StatusCode::OK, status.error_code());
}

void assert_vectors_are_equal(std::vector<std::string> expected_vector, std::vector<std::string> actual_vector)
{
  ASSERT_EQ(expected_vector.size(), actual_vector.size());

  for (int i = 0; i < expected_vector.size(); ++i) {
    EXPECT_EQ(expected_vector[i], actual_vector[i]);
  }
}

TEST(DeviceEnumeratorTests, CreateDeviceEnumeratorWithMockLibrary_CallEnumerateDevices_ReturnsExpectedNameOfDevices)
{
  DeviceEnumeratorMockLibrary mock_library;
  ni::hardware::grpc::internal::DeviceEnumeratorNew device_enumerator(&mock_library);
  google::protobuf::RepeatedPtrField<ni::hardware::grpc::DeviceProperties> devices;
  mock_library.DelegateToFake();

  ::grpc::Status status = device_enumerator.enumerate_devices(&devices);

  std::vector<std::string> expected_device_names{"SimulatedScope1", "SimulatedSwitch1"};
  std::vector<std::string> actual_device_names{};
  for (auto it : devices) {
    actual_device_names.push_back(it.name());
  }
  assert_vectors_are_equal(expected_device_names, actual_device_names);
}

}  // namespace unit
}  // namespace tests
}  // namespace ni
