//
// Created by jimy on 5/17/20.
//

#ifndef AUTODEDUCTIONV2_PROTO_HELPER_H
#define AUTODEDUCTIONV2_PROTO_HELPER_H
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <google/protobuf/text_format.h>

using google::protobuf::Message;
bool ReadProtoFromTextFile(const char* filename, Message* proto);
#endif //AUTODEDUCTIONV2_PROTO_HELPER_H
