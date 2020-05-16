//
// Created by jimy on 5/12/20.
//

#ifndef AUTODEDUCTIONV2_ADCLIENT_H
#define AUTODEDUCTIONV2_ADCLIENT_H

#include <iostream>
#include <memory>
#include <string>

#include "grpc++/grpc++.h"

#include "../proto/autodeduction.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using auto_deduction::RegisterServiceRequest;
using auto_deduction::RegisterServiceReply;
using auto_deduction::CancelServiceRequest;
using auto_deduction::CancelServiceReply;
using auto_deduction::UserItemListRequest;
using auto_deduction::UserItemListReply;
using auto_deduction::ItemListRequest;
using auto_deduction::ItemListReply;
using auto_deduction::AutoDeduction;

class AutoDeductionServiceClient {
public:
  AutoDeductionServiceClient(std::shared_ptr<Channel> channel)
    : stub_(AutoDeduction::NewStub(channel)) {}

  std::string RegisterService(int service_id) {
    RegisterServiceRequest request;
    RegisterServiceReply reply;
    ClientContext context;
    request.set_uid(1);
    request.set_service_id(service_id);
    Status status = stub_ -> RegisterService(&context, request, &reply);

    if (status.ok()) {
      switch(reply.state()) {
        case reply.SUCCESS:
          std::cout << "订阅成功" << std::endl;
          break;
        case reply.ALREADY_REGISTER:
          std::cout << "您已经订阅过该项目，无需重复订阅" << std::endl;
          break;
        default:
          std::cout << "抱歉， 发生了未知的错误" << std::endl;
      }
    }
  };

  std::string CancelService(int service_id) {
    CancelServiceRequest request;
    CancelServiceReply reply;
    ClientContext context;
    request.set_uid(1);
    request.set_service_id(service_id);
    Status status = stub_ -> CancelService(&context, request, &reply);

    if (status.ok()) {
      std::cout << reply.state();
      switch(reply.state()) {
        case reply.SUCCESS:
          std::cout << "取消成功" << std::endl;
          break;
        case reply.NOT_REGISTER:
          std::cout << "您并没有订阅过该项目" << std::endl;
          break;
        default:
          std::cout << "抱歉， 发生了未知的错误" << std::endl;
      }
    }
  };

  std::string GetUserItemList() {
    UserItemListRequest request;
    UserItemListReply reply;

    ClientContext context;
    request.set_uid(1);
    Status status = stub_ -> GetUserItemList(&context, request, &reply);

    if (status.ok()) {
      for (int i=0; i < reply.service_item().size(); i++) {
        std::cout << reply.service_item(i).id() << ", " << reply.service_item(i).name() << std::endl;
      }
    } else {
      std::cout << status.error_code() << ": " << status.error_message()
                << std::endl;
      return "RPC failed";
    }

  }

  std::string GetItemList() {
    ItemListRequest request;
    ItemListReply reply;

    ClientContext context;

    Status status = stub_ -> GetItemList(&context, request, &reply);

    if (status.ok()) {
      for (int i=0; i < reply.service_item().size(); i++) {
        std::cout << reply.service_item(i).id() << ", " << reply.service_item(i).name() << std::endl;
      }
    } else {
      std::cout << status.error_code() << ": " << status.error_message()
                << std::endl;
      return "RPC failed";
    }
  }
private:
  std::unique_ptr<AutoDeduction::Stub> stub_;
};

#endif //AUTODEDUCTIONV2_ADCLIENT_H
