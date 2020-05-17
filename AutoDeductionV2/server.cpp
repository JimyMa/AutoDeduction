#include <iostream>
#include "service.h"
#include <gflags/gflags.h>

DEFINE_string(config_file, "", "prototxt file to store tmp"); // NOLINT

int main(int argc, char** argv) {
  ::gflags::ParseCommandLineFlags(&argc, &argv, true);
  RunServer(FLAGS_config_file);
  return 0;
}