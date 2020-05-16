//
// Created by jimy on 5/12/20.
//

#include "dbserver.h"
#include <iostream>

using namespace std;

DBServer::DBServer() {
  m_SQLCON = mysql_init(nullptr);
  mysql_set_character_set(m_SQLCON, "utf8");
  if (m_SQLCON == nullptr) {
    std::cerr << "cannot connect to mysql grpc_server" << std::endl;
    exit(1);
  }
  if(
      mysql_real_connect(m_SQLCON, "localhost", "root", "hello123",
                         "auto_deduction", 0, nullptr, CLIENT_MULTI_STATEMENTS)
      ) {
  } else {
    fprintf(stderr, "%s\n", mysql_error(m_SQLCON));
    mysql_close(m_SQLCON);
    exit(1);
  }
}

int DBServer::Insert(string cmd) {
  mysql_query(m_SQLCON, cmd.c_str());
  return 0;
}

int DBServer::Delete(string cmd){
  mysql_query(m_SQLCON, cmd.c_str());
  return 0;
}

int DBServer::Query(string cmd, vector<vector<string>> &table) {
  mysql_query(m_SQLCON, cmd.c_str());

  MYSQL_RES *res = mysql_store_result(m_SQLCON);

  // 获取列数
  unsigned int num_fields = mysql_num_fields(res);

  // 获取行数

  MYSQL_ROW row;

  for (int i = 0; i < num_fields; i++) {
    vector<string> col_vector;
    table.push_back(col_vector);
  }

  while (row = mysql_fetch_row(res)) {
    for (int i = 0; i < num_fields; i++) {
      table[i].push_back(row[i]);
    }
  }

  mysql_free_result(res);

  return 0;
}

std::shared_ptr<DBServer> DBServer::m_pDBServer = nullptr;
bool DBServer::m_OK = false;


