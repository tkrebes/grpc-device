<%
import common_helpers
import service_helpers

attributes = data['attributes']
enums = data['enums']
config = data['config']
functions = data['functions']

used_enums = common_helpers.get_used_enums(functions, attributes)
enums_to_map = [e for e in enums if e in enums and enums[e].get("generate-mappings", False)]
service_class_prefix = config["service_class_prefix"]
include_guard_name = service_helpers.get_include_guard_name(config, "_SERVICE_H")
namespace_prefix = config["namespace_component"] + "_grpc::"
if len(config["custom_types"]) > 0:
  custom_types = config["custom_types"]
%>\

//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Service header for the ${config["driver_name"]} Metadata
//---------------------------------------------------------------------
#ifndef ${include_guard_name}
#define ${include_guard_name}

#include <${config["module_name"]}.grpc.pb.h>
#include <condition_variable>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <map>
#include <server/session_repository.h>
#include <server/shared_library.h>

#include "${config["module_name"]}_library_interface.h"

namespace ${config["namespace_component"]}_grpc {

class ${service_class_prefix}Service final : public ${service_class_prefix}::Service {
public:
  ${service_class_prefix}Service(${service_class_prefix}LibraryInterface* library, nidevice_grpc::SessionRepository* session_repository);
  virtual ~${service_class_prefix}Service();
% for function in common_helpers.filter_proto_rpc_functions(functions):
<%
  f = functions[function]
  method_name = common_helpers.snake_to_pascal(function)
%>\
  ::grpc::Status ${method_name}(::grpc::ServerContext* context, const ${method_name}Request* request, ${method_name}Response* response) override;
% endfor
private:
  ${service_class_prefix}LibraryInterface* library_;
  nidevice_grpc::SessionRepository* session_repository_;
% if common_helpers.has_viboolean_array_param(functions):
  void Copy(const std::vector<ViBoolean>& input, google::protobuf::RepeatedField<bool>* output);
% endif
% if 'custom_types' in locals():
%   for custom_type in custom_types:
  void Copy(const ${custom_type["name"]}& input, ${namespace_prefix}${custom_type["grpc_name"]}* output);
  void Copy(const std::vector<${custom_type["name"]}>& input, google::protobuf::RepeatedPtrField<${namespace_prefix}${custom_type["grpc_name"]}>* output);
%   endfor
% endif
% for enum in enums_to_map:
<%
  enum_value = service_helpers.python_to_c(enums[enum])
%>\
  std::map<std::int32_t, ${enum_value}> ${enum.lower()}_input_map_ { ${service_helpers.get_input_lookup_values(enums[enum])} };
  std::map<${enum_value}, std::int32_t> ${enum.lower()}_output_map_ { ${service_helpers.get_output_lookup_values(enums[enum])} };
% endfor
};

} // namespace ${config["namespace_component"]}_grpc

#endif  // ${include_guard_name}
