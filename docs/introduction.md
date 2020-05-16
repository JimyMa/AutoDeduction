# 使用说明

首先对程序进行编译：

``` shell
mkdir build && cd build
cmake ..
make all
```

TODO: 采用 bazel 构建程序

## 服务端

- 在 mysql 命令行下运行 `script/create_database.sql` 脚本

``` mysql
source create_database.sql
```
- 运行 Server 程序

``` shell
./Server
```

## 客户端

- 直接运行可执行文件即可

``` shell
./Client
```
