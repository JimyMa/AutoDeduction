//
// Created by jimy on 5/12/20.
//

#ifndef AUTODEDUCTIONV2_SERVER_H
#define AUTODEDUCTIONV2_SERVER_H

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <string>
#include <cstring>

#include <grpc++/grpc++.h>

#include "../proto/autodeduction.grpc.pb.h"
#include "../db/dbserver.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using auto_deduction::RegisterServiceRequest;
using auto_deduction::RegisterServiceReply;
using auto_deduction::CancelServiceRequest;
using auto_deduction::CancelServiceReply;
using auto_deduction::ItemListRequest;
using auto_deduction::ItemListReply;
using auto_deduction::UserItemListRequest;
using auto_deduction::UserItemListReply;
using auto_deduction::AutoDeduction;
using auto_deduction::ServiceItem;

using namespace std;

class AutoDeductionImpl final : public AutoDeduction::Service{
  Status RegisterService(ServerContext* context,
                         const RegisterServiceRequest* request,
                         RegisterServiceReply* reply) override {
    std::shared_ptr<DBServer> db_server = DBServer::getDBServer();

    // 查看是不是有这个用户
    vector<vector<string>> user_id;
    db_server -> Query("select * from user where id=" + std::to_string(request->uid()) + ";", user_id);

    if(user_id[0].empty()) {
      reply -> set_state(reply->UID_FAIL);
      return Status::OK;
    }

    // 查看是不是有这个服务号
    vector<vector<string>> service_id;
    db_server -> Query("select * from service where id=" + std::to_string(request->service_id()) + ";", service_id);

    if(user_id[0].empty()) {
      reply -> set_state(reply->SERVICE_ID_FAIL);
      return Status::OK;
    }

    // 查看这个服务是不是已经被订阅
    vector<vector<string>> user_book_info;
    // 查看是不是有这个服务号
    db_server -> Query("select * from user_book_info where user_id=" +
                       std::to_string(request->uid()) +
                       " and service_id=" +
                       std::to_string(request->service_id()) +
                       ";", user_book_info);

    if(!user_book_info[0].empty()) {
      reply -> set_state(reply->ALREADY_REGISTER);
      return Status::OK;
    }
    db_server -> Insert("insert user_book_info(user_id, service_id) VALUES (" +
                        std::to_string(request->uid()) +
                        ", " +
                        std::to_string(request->service_id()) +
                        ")");

    // 查询一次是否订阅成功
    vector<vector<string>> user_book_info_inserted;
    // 查看是不是有这个服务号
    db_server -> Query("select * from user_book_info where user_id=" +
                       std::to_string(request->uid()) +
                       " and service_id=" +
                       std::to_string(request->service_id()) +
                       ";", user_book_info_inserted);
    if(!user_book_info_inserted.empty())
      reply -> set_state(reply->SUCCESS);
    else
      reply -> set_state(reply->UNKNOWN_FAIL);
    return Status::OK;
  }

  Status CancelService(ServerContext* context,
                       const CancelServiceRequest* request,
                       CancelServiceReply* reply) override {
    std::shared_ptr<DBServer> db_server = DBServer::getDBServer();

    // 查看是不是有这个用户
    vector<vector<string>> user_id;
    db_server -> Query("select * from user where id=" + std::to_string(request->uid()) + ";", user_id);

    if(user_id[0].empty()) {
      reply -> set_state(reply->UID_FAIL);
      return Status::OK;
    }

    // 查看是不是有这个服务号
    vector<vector<string>> service_id;
    db_server -> Query("select * from service where id=" + std::to_string(request->service_id()) + ";", service_id);

    if(user_id[0].empty()) {
      reply -> set_state(reply->SERVICE_ID_FAIL);
      return Status::OK;
    }

    // 查看这个服务是不是已经被订阅
    vector<vector<string>> user_book_info;
    // 查看是不是没有订阅这个服务号
    db_server -> Query("select * from user_book_info where user_id=" +
                       std::to_string(request->uid()) +
                       " and service_id=" +
                       std::to_string(request->service_id()) +
                       ";", user_book_info);

    if(user_book_info[0].empty()) {
      reply -> set_state(reply->NOT_REGISTER);
      return Status::OK;
    }
    db_server -> Delete("delete from user_book_info where user_id=" +
                        std::to_string(request->uid()) +
                        " and service_id=" +
                        std::to_string(request->service_id()) +
                        ";"
                        );

    // 查询一次是否取消成功
    vector<vector<string>> user_book_info_deleted;
    // 查看是不是有这个服务号
    db_server -> Query("select * from user_book_info where user_id=" +
                       std::to_string(request->uid()) +
                       " and service_id=" +
                       std::to_string(request->service_id()) +
                       ";", user_book_info_deleted);
    if(user_book_info_deleted[0].empty())
      reply -> set_state(reply->SUCCESS);
    else
    {
      reply -> set_state(reply->UNKNOWN_FAIL);
    }
    return Status::OK;
  }

  Status GetUserItemList(ServerContext* context,
                         const UserItemListRequest* request,
                         UserItemListReply* reply) override {
    std::shared_ptr<DBServer> db_server = DBServer::getDBServer();

    vector<vector<string>> service_id;
    int uid = request -> uid();
    string query_string = "select * from user_book_info where user_id=" + std::to_string(uid) + ";";
    db_server -> Query(query_string, service_id);

    string all_id = "";
    for (int i = 0; i < service_id[2].size(); i++) {
      if (i == 0)
        all_id += "(";

      all_id += service_id[2][i];

      if (i != service_id[2].size() - 1)
        all_id += ",";
      else
        all_id += ")";
    }

    string user_service_list_sql_query = "select * from service where id in " + all_id + ";";

    vector<vector<string>> table;

    db_server -> Query(user_service_list_sql_query, table);

    for (int i = 0; i < table[0].size(); i++) {
      reply -> add_service_item();
      reply -> mutable_service_item(i) -> set_id(std::stoi(table[0][i]));
      reply -> mutable_service_item(i) -> set_name(table[1][i]);
    }

    return Status::OK;
  }

  Status GetItemList(ServerContext* context,
                     const ItemListRequest* request,
                     ItemListReply* reply) override {

    std::shared_ptr<DBServer> db_server = DBServer::getDBServer();
    vector<vector<string>> table;

    db_server -> Query("select * from service;", table);

    for (int i = 0; i < table[0].size(); i++) {
      reply -> add_service_item();
      reply -> mutable_service_item(i) -> set_id(std::stoi(table[0][i]));
      reply -> mutable_service_item(i) -> set_name(table[1][i]);
    }

    return Status::OK;
  }
};

void RunServer(string config_file);

#endif //AUTODEDUCTIONV2_SERVER_H
