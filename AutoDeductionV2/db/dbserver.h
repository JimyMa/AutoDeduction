//
// Created by jimy on 5/12/20.
//

#ifndef AUTODEDUCTIONV2_DB_H
#define AUTODEDUCTIONV2_DB_H

#include <mutex>
#include <memory>
#include <atomic>

#include <vector>

#include "mysql/mysql.h"

using namespace std;

class DBServer {
public:
  static std::shared_ptr<DBServer> getDBServer() {
    if (DBServer::m_pDBServer != nullptr) {
      return m_pDBServer;
    } else {
      std::mutex mtx;
      std::lock_guard<std::mutex> lock(mtx);
      if (!m_OK) {
        m_pDBServer = std::shared_ptr<DBServer> (new DBServer());
        m_OK = true;
      }
      return m_pDBServer;
    }
  }

  int Insert(string cmd);
  int Delete(string cmd);

  int Query(string cmd, vector<vector<string>> & table);

  ~DBServer() {
    mysql_close(m_SQLCON);
  }

private:
  explicit DBServer();
  void finishQuery() {
    MYSQL_RES* pRes;
    do {
      pRes = mysql_use_result(m_SQLCON);
      mysql_free_result(pRes);
    } while (!mysql_next_result(m_SQLCON));
  }

  MYSQL *m_SQLCON;
  static std::shared_ptr<DBServer> m_pDBServer;
  static std::mutex m_mtx;
  static bool m_OK;
};


#endif //AUTODEDUCTIONV2_DB_H
