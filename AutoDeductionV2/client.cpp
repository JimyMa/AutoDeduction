//
// Created by jimy on 5/12/20.
//

#include "grpc++/grpc++.h"
#include "client/client.h"
#include <gflags/gflags.h>
#include <fstream>

#include "utils/proto_helper.h"
#include "utils/get_file_content.h"
#include "proto/client_config.pb.h"

using namespace std;
using client_config::ClientConfig;

DEFINE_string(config_file, "", "prototxt file to store tmp"); //NO LINT

int main(int argc, char* argv[]) {
  // Google flags.
  ::gflags::ParseCommandLineFlags(&argc, &argv, true);

  // 读取配置参数文件
  ClientConfig config;
  ReadProtoFromTextFile(FLAGS_config_file.c_str(), &config);

  string clientkey = get_file_contents(config.clientkey_path().c_str());
  string servercert = get_file_contents(config.servercert_path().c_str());
  string clientcert = get_file_contents(config.clientcert_path().c_str());

  grpc::SslCredentialsOptions ssl_opts;
  ssl_opts.pem_root_certs = servercert;
  ssl_opts.pem_private_key = clientkey;
  ssl_opts.pem_cert_chain  = clientcert;

  std::shared_ptr<grpc::ChannelCredentials> creds = grpc::SslCredentials(ssl_opts);

  AutoDeductionServiceClient greeter(grpc::CreateChannel(
      "localhost:50051", creds));

  int user_id;
  cout << "请输入用户 id:" << endl;
  cin >> user_id;

  while(true) {

    cout << "\n您好，欢迎光临自动扣费系统" << endl;
    cout << "请选择你需要的服务:" << endl;
    cout << "\t1. 查询所有的扣费服务" << endl;
    cout << "\t2. 查询您已经办理的扣费服务" << endl;
    cout << "\t3. 扣费服务订阅" << endl;
    cout << "\t4. 取消扣费服务" << endl;
    cout << "\t0. 退出" << endl;

    int c;
    cin >> c;
    switch (c) {
      case 1:
      {
        std::string reply = greeter.GetItemList();
        break;
      }

      case 2:
      {
        std::string reply = greeter.GetUserItemList(user_id);
        break;
      }

      case 3:
      {
        cout << "请输入想要订阅的服务号" << endl;
        int service_id;
        cin >> service_id;
        std::string reply = greeter.RegisterService(user_id, service_id);
        break;
      }

      case 4:
      {
        cout << "请输入想要取消的服务号" << endl;
        int service_id;
        cin >> service_id;
        std::string reply = greeter.CancelService(user_id, service_id);
        break;
      }

      case 0:
        return 0;
      default:
        cout << "输入错误，请重新输入" << endl;
    }
  }
}

