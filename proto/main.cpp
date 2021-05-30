#include <google/protobuf/service.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>

#include "file.grpc.pb.h"
#include "file.pb.h"
#include "sum.h"

class SummatorImpl final : public example::Summator::Service {
public:
  grpc::Status Sum(grpc::ServerContext* context, const example::InputData* request, example::Result* response) override {
    response->set_res(::Sum(request->a(), request->b()));
    return grpc::Status::OK;
  }
};

void RunServer() {
  // This parts is taken from the "hello world" gRPC sample.
  using namespace std::string_literals;

  const std::string server_address = "0.0.0.0:50051"s;
  SummatorImpl service;

  grpc::ServerBuilder builder;
  // Listen on the given address without any authentication mechanism.
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  // Register "service" as the instance through which we'll communicate with
  // clients. In this case it corresponds to an *synchronous* service.
  builder.RegisterService(&service);
  // Finally assemble the server.
  std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << server_address << std::endl;

  // Wait for the server to shutdown. Note that some other thread must be
  // responsible for shutting down the server for this call to ever return.
  server->Wait();
}

int main() {
  RunServer();
  return 0;
}