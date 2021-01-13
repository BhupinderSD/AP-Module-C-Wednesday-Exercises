#include <iostream>
#include <fstream>
#include <sys/stat.h>

//Exercise 1: File Exists
//https://repl.it/join/jnmkprxm-bhupindersd
//https://repl.it/@BhupinderSD/File-Exists

std::string getLine(std::string request) {
  std::string string;
  std::cout << request;
  getline(std::cin, string);
  return string;
}

bool fileExists(std::string filename) {
  struct stat buffer;
  if (stat(filename.c_str(), &buffer) == 0) { //check if the file exists
    std::cout << filename << ", " << buffer.st_size << " bytes, last modified: " << ctime(&buffer.st_mtime) << std::endl; //print the file name, size and last modified time
    return true;
  }
  return false;
}

int main() {
  std::string filename = getLine("Filename to check: "); //get the file name

  if (!fileExists(filename)) {
    std::cout << filename << " does not exist\n"; //print a message if the file does not exist
  }
}
