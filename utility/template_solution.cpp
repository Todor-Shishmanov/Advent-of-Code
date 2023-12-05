#include <fstream>
#include <iostream>
#include <cassert>
#include <string>

#define DEBUG_LEVEL 1

void solution(std::ifstream& in_f);

int main(int argc, char *argv[]) {
  if(argc != 2){
    std::cout << "Wrong number of arguments!\n";
    return 1;
  }
    
  std::ifstream in_f(argv[1]);
  if(!in_f.is_open()){
    std::cout << "Couldn't open file " << argv[1] << '\n';
    return 1;
  }

  solution(in_f);
  return 0;
}

void solution(std::ifstream& in_f) {
  /* Simple debug like */
  #if DEBUG_LEVEL == 1
  std::cout << "Hello world\n";
  #endif

  std::string line;
  while(std::getline(in_f, line)){
    // Assert as much as possible!
    assert(line.size() != 0);

    /* Add stuff here */
  }
  
  return;
}