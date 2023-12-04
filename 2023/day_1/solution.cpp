#include <fstream>
#include <iostream>
#include <string>
#include <cassert>

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
// one, two, three, four, five, six, seven, eight, and nine
int find_digit_from_arr(const char start[], size_t size){
  assert(start != nullptr);
  int error = -1;
  if(size < 3 ) return error;
  if(size > 5) size = 5;

  if(start[0] == 'z' && size >= 4 &&  start[1] == 'e' && start[2] == 'r' && start[3] == 'o') return 0;
  else if(start[0] == 'o' && size >= 3 && start[1] == 'n' && start[2] == 'e') return 1;
  else if(start[0] == 't') {
    if (size >= 3 &&  start[1] == 'w' && start[2] == 'o') return 2;
    else if (size == 5 &&  start[1] == 'h' && start[2] == 'r' && start[3] == 'e' && start[4] == 'e') return 3;
    else return error;
  } 
  else if (start[0] == 'f' && size >= 4){
    if(start[1] == 'o' && start[2] == 'u' && start[3] == 'r') return 4;
    else if (start[1] == 'i' && start[2] == 'v' && start[3] == 'e') return 5;
    else return error;
  }
  else if (start[0] == 's') {
    if(size >= 3 &&  start[1] == 'i' && start[2] == 'x') return 6;
    else if (size == 5 &&  start[1] == 'e' && start[2] == 'v' && start[3] == 'e' && start[4] == 'n') return 7;
    else return error;
  }
  else if (start[0] == 'e' && size == 5 && start[1] == 'i' && start[2] == 'g' && start[3] == 'h' && start[4] == 't') return 8;
  else if (start[0] == 'n' && size >= 4 &&  start[1] == 'i' && start[2] == 'n' && start[3] == 'e') return 9;
  else return error;
}

void solution(std::ifstream& in_f){
  std::string line;
  unsigned sum = 0;

  #if DEBUG >= 1
  int max_cicle = 10;
  #endif

  size_t line_size;
  unsigned first_digit, last_digit;
  bool digit_found;
  size_t iterator;
  while(std::getline(in_f, line)){
    #if DEBUG >= 1
    std::cout << "Cycle: " << 11 - max_cicle << '\n';
    #endif
    line_size = line.size();
    iterator = 0;
    first_digit = 0; 
    last_digit = 0;
    digit_found = false;

    // Find first number
    digit_found = false;
    for(; iterator < line_size; ++iterator){
      if(std::isdigit(line[iterator])) {
        first_digit = line[iterator] - '0';
        digit_found = true;
        break;
      }
      // Solution 2
      int possible_digit = find_digit_from_arr(line.c_str() + iterator, line_size - iterator);
      if(possible_digit >= 0 && possible_digit <= 9){
        first_digit = possible_digit;
        #if DEBUG >= 2
        std::cout << "Found via function: starting at index " << iterator << " line_size: " << line_size << " iterator: " << iterator << ' ';
        #endif
        digit_found = true;
        break;
      }
    }
    assert(digit_found);
    #if DEBUG >= 1
    std::cout << "First: " << first_digit << '\n';
    #endif

    // Find last number
    unsigned first_digit_pos = iterator;
    digit_found = false;
    for(iterator = line_size - 1; iterator >= first_digit_pos; --iterator){
      if(std::isdigit(line[iterator])) {
        last_digit = line[iterator] - '0';
        digit_found = true;
        break;
      }
      // Solution 2
      int possible_digit = find_digit_from_arr(line.c_str() + iterator, line_size - iterator);
      if(possible_digit >= 0 && possible_digit <= 9){
        last_digit = possible_digit;
        #if DEBUG >= 2
        std::cout << "Found via function: starting at index " << iterator << " line_size: " << line_size << " iterator: " << iterator << ' ';
        #endif
        digit_found = true;
        break;
      }
    }
    assert(digit_found);
    #if DEBUG >= 1
    std::cout << "Last: " << last_digit << "\nTogether: " << first_digit * 10 + last_digit << "\n\n";
    #endif
    // Add to sum
    sum += first_digit * 10 + last_digit;

    #if DEBUG >= 1
    if(max_cicle-- == 0)
      break;
    #endif
  }

  std::cout << "Sum: " << sum << '\n';
}