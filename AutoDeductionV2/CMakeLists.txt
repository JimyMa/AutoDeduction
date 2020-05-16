cmake_minimum_required(VERSION 3.10)
project(AutoDeductionV2 C CXX)

set(CMAKE_CXX_STANDARD 14)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
find_package(MySQL REQUIRED)
find_package(Protobuf REQUIRED)

include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(proto)
include_directories(db)
include_directories(service)
include_directories(client)

add_executable(Server server.cpp proto/autodeduction.pb.cc proto/autodeduction.grpc.pb.cc db/dbserver.cpp service/service.cpp)
target_link_libraries(Server ${Protobuf_LIBRARIES})
target_link_libraries(Server /usr/local/lib/libgrpc.so /usr/local/lib/libgrpc++.so)
target_link_libraries(Server ${MYSQL_LIBRARY})

add_executable(Client client.cpp proto/autodeduction.pb.cc proto/autodeduction.grpc.pb.cc client/client.cpp)
target_link_libraries(Client ${Protobuf_LIBRARIES})
target_link_libraries(Client /usr/local/lib/libgrpc.so /usr/local/lib/libgrpc++.so)

add_executable(TryDB try_db.cpp db/dbserver.cpp)
target_link_libraries(TryDB ${MYSQL_LIBRARY})
