//
// Created by jimy on 5/12/20.
//

#include "service.h"
#include "../proto/server_config.pb.h"
#include "../utils/get_file_content.h"
#include "../utils/proto_helper.h"
#include <fstream>

using server_config::ServerConfig;

void RunServer(string config_file) {
  std::string server_address("localhost:50051");

  // 读取配置参数文件
  ServerConfig config;
  ReadProtoFromTextFile(config_file.c_str(), &config);

  string serverkey = get_file_contents(config.serverkey_path().c_str());
  string servercert = get_file_contents(config.servercert_path().c_str());
  string clientcert = get_file_contents(config.clientcert_path().c_str());

  AutoDeductionImpl service;

  grpc::SslServerCredentialsOptions::PemKeyCertPair pkcp = {
      serverkey, servercert
  };

  grpc::SslServerCredentialsOptions ssl_opts(GRPC_SSL_REQUEST_AND_REQUIRE_CLIENT_CERTIFICATE_AND_VERIFY);
  ssl_opts.pem_root_certs = clientcert;
  ssl_opts.pem_key_cert_pairs.push_back(pkcp);

  std::shared_ptr<grpc::ServerCredentials> creds;
  creds = grpc::SslServerCredentials(ssl_opts);

  ServerBuilder builder;
  // Listen on the given address without any authentication mechanism.
  builder.AddListeningPort(server_address, creds);
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