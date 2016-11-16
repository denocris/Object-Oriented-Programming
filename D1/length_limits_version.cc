#include <iostream>
#include <limits>

/*

This program calculate the length of some type using the limits library

*/


int main()
{

  int maxint = std::numeric_limits<int>::max();

  std::cout << maxint << std::endl;

  int next = maxint + 10000;

  std::cout << next << std::endl;

  unsigned int test = next;

  std::cout << test << std::endl;

  long int test2 = next;

  std::cout << test2 << std::endl;


  return 0;
}
