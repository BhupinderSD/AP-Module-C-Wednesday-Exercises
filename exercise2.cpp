#include <iostream>
#include <fstream>
#include <sys/stat.h>

//Exercise 2: File Writer
//https://repl.it/join/ihzlfljg-bhupindersd
//https://repl.it/@BhupinderSD/File-Writer

void flushBuffer() {
    std::cin.clear(); //resets the cin stream state so that future I/O operations work correctly
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); //clears the cin buffer including new lines or additional characters
}

std::string getLine(std::string request) {
  std::string string;
  std::cout << request;
  getline(std::cin, string);
  return string;
}

char getChar(std::string request) {
  std::cout << request;
  char addAnother = toupper(getchar()); //take the first character and accept upper and lower case characters 
  if (std::cin.fail()) {
    addAnother = '0'; //use 0 to represent an invalid input
  }
  flushBuffer(); //clears any remaining characters and clears any the stream state
  return addAnother;
}

bool fileExists(std::string filename) {
  struct stat buffer;
  bool fileExists = stat(filename.c_str(), &buffer) == 0; //check if the file exists
  return fileExists; 
}

void addFileContents(std::string content) {
  std::string filename = "list.csv";
  std::ofstream file;

  if (fileExists(filename)) { //check if the file exists
    std::cout << "Updating file...\n";      
    file.open(filename, std::ios_base::app); //appends/adds to the end of the existing file
  } else {
    std::cout << "Creating file...\n";      
    file.open(filename, std::ios_base::out); //creates a new file or overrides the existing
  }

  file << content << std::endl; //add the file content to the file
  file.close(); //close the file stream
}

int main() {
  while (true) { //keep asking for names until the users doesn't want to add another 
    std::string name = getLine("\nEnter name: "); //get the name to add to the file
    
    addFileContents(name); //add the name to the file

    char shouldAddAnother = getChar("\nAdd another (y/n)? ");
    if (shouldAddAnother == 'Y') {
      continue; //runs the loop again
    } else if (shouldAddAnother == 'N') {
      break; //closes the program by breaking the loop
    } else {
      std::cout << "Invalid input, closing program\n\n";
      break; //closes the program if the user enters an invalid input 
    }
  }

  std::cout << "Goodbye" << std::endl;

  return 0;
}
