#include <iostream>
#include <fstream>
#include <sys/stat.h>

//Exercise 3: File Reader
//https://repl.it/join/lljpjptj-bhupindersd
//https://repl.it/@BhupinderSD/Exercise-3-File-Reader

std::string getLine(std::string request) {
  std::string string;
  std::cout << request;
  getline(std::cin, string);
  return string;
}

bool fileExists(std::string filename) {
  struct stat buffer;
  bool fileExists = stat(filename.c_str(), &buffer) == 0; //check if the file exists
  return fileExists; 
}

void readFileContents(std::string filename) {
  std::ifstream file;
  std::string line;
  int lineNumber = 0;

  file.open(filename); //open the file to read it

  while (!file.eof()) { //while we are not at the end of the file
    lineNumber++; //increment the line number count
    getline(file, line); //read the line
    std::cout << lineNumber << ". " << line << std::endl; //print the line contents
  }

  file.close(); //close the file stream

  std::cout << "\nTotal number of lines read: " << lineNumber << std::endl; //print the number of lines read
}

int main() {
  std::string filename = getLine("\nPlease enter a valid filename: "); //get the filename

  if (!fileExists(filename)) { //check if the file does not exist
    std::cout << "Sorry, \'" << filename << "\' does not exist.\n";
    return 0; //close the program if the file does not exist
  }

  readFileContents(filename); //print the file contents

  return 0;
}
