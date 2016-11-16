#include <iostream>
#include "sign_hello.hh"

int main(){

  int repeats;
  int npos = 0;
  int nneg = 0;

  std::cout << "How many repeats? ";
  std::cin >> repeats;

  for( int i=0; i < repeats; i++){

    std::cout << "Write an integer number: ";

    int num;
    std::cin >> num;

    std::cout << num << " is "
              << sign_of_num(num, npos, nneg)
              << std::endl;
  }

  std::cout << "Npos: " << npos << "\n";
  std::cout << "Nneg: " << nneg << std::endl;


  return 0;
}
