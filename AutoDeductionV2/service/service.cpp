//
// Created by jimy on 5/12/20.
//

#include "service.h"

void RunServer() {
  std::string server_address("localhost:50051");
  AutoDeductionImpl service;

  ServerBuilder builder;
  // Listen on the given address without any authentication mechanism.
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  // Register "client" as the instance through which we'll communicate with
  // clients. In this case it corresponds to an *synchronous* client.
  builder.RegisterService(&service);
  // Finally assemble the server.
  std::unique_ptr<Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << server_address << std::endl;

  // Wait for the server to shutdown. Note that some other thread must be
  // responsible for shutting down the server for this call to ever return.
  server->Wait();
}