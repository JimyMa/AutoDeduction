//
// Created by jimy on 5/12/20.
//

#include "grpc++/grpc++.h"
#include "client/client.h"

using namespace std;

int main(int argc, char* argv[]) {
  int user_id;
  cout << "请输入用户 id:" << endl;
  cin >> user_id;

  AutoDeductionServiceClient greeter(grpc::CreateChannel(
      "localhost:50051", grpc::InsecureChannelCredentials()));

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

