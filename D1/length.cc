#include <iostream>

/*

This program calculate the length of some type

*/


int main()
{
  int a = 1;
  unsigned b = 1;
  //long c = 1; // more sophisticated to handle!
  //unsigned long d = 1; // more sophisticated to handle!


  while( a > 0){
    a++;
  }
  std::cout << "here the max int: " << a - 1 << "\n";
  std::cout << "Look at the next: " << a << "\n";

  while( b > 0){
    b++;
  }
  std::cout << "Max_num unsigned: " << b - 1 << "\n";
  std::cout << "Look at the next: " << b << std::endl;

  return 0;
}
