#include <iostream>


int main()
{
  int a;
  double b;


  std::cout << "Write an integer number: ";
  std::cin >> a;

  if( a > 0){
    std::cout << "The numebr is positive: "  << a <<  std::endl;
  }
  else if( a == 0){
    std::cout << "The numebr is zero: "  << a <<  std::endl;
  }
  else{
    std::cout << "The numebr is negative: "  << a <<  std::endl;
  }



  std::cout << "Write an real number: ";
  std::cin >> b;

  //std::cout << "Hello World, integer: " << a << "\n";
  std::cout << "Hello World, real: " << b << std::endl;

  return 0;
}
