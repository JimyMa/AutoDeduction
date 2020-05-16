//
// Created by jimy on 5/12/20.
//

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <string>
#include <cstring>

#include "../db/dbserver.h"

int main() {
  std::shared_ptr<DBServer> db_server = DBServer::getDBServer();
  vector<vector<string>> table;
  vector<vector<string>> service_id;

  db_server -> Query("select * from user_book_info;", table);
  db_server -> Query("select * from service;", service_id);
  return 0;
}
