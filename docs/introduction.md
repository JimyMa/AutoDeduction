# 使用说明

首先对程序进行编译,并且生成 PB 文件对应的 CPP 和 GRPC 文件，以及生成通过 OPENSSL 生成的私钥和证书

``` shell
cd proto
protoc --cpp_out=./ autodeduction.proto client_connfig.proto server_config.proto
protoc --grpc_out=./ --plugin=grpc_cpp_plugin  autodeduction.proto
cd ..
mkdir openssl
cd scripts
./gen_openssl.h
mkdir build && cd build
cmake ..
make all
```

TODO: 采用 bazel 构建程序
TODO: 自动生成 grpc 和 pb file

## 服务端

- 将 openssl 生成的文件路径保存到配置文件中，配置文件的格式详见 "proto/server_config.proto"
- 在 mysql 命令行下运行 `script/create_database.sql` 脚本

``` mysql
source create_database.sql
```
- 运行 Server 程序

``` shell
./Server --config_file "YOUR_CONFIG_FILE_PATH"
```

## 客户端
- 将 openssl 生成的文件路径保存到配置文件中，配置文件的格式详见 "proto/client_config.proto"
- 运行

``` shell
./Client --config_file "YOUR_CONFIG_FILE_PATH"
```
