//
// Created by jimy on 5/17/20.
//

#include "get_file_content.h"
#include <fstream>


std::string get_file_contents(const char* fpath) {
  std::ifstream finstream(fpath);
  std::string contents;
  contents.assign((std::istreambuf_iterator<char>(finstream)), std::istreambuf_iterator<char>());
  finstream.close();
  return contents;
}

