#include <iostream>
#include <string>

/*
void sign_of_num(int number){


    if( number > 0){
      std::cout << "The numebr is positive: "  << number <<  std::endl;
      //++npos;
    }
    else if( number == 0){
      std::cout << "The numebr is zero: "  << number <<  std::endl;
    }
    else{
      std::cout << "The numebr is negative: "  << number <<  std::endl;
      //++npos;
    }
}
*/

std::string sign_of_num(const int number, int & npos, int & nneg){

  // & means pass by reference and it will talk with the global variable in the main.
  // Withot &, these varibles are local (and just a copy of the value in the main) and will not intercat with the global ones defined in mani

  // if you know that a varible must be constant, it is better to put it!!

    std::string result; // nedeed for simpler strings

    if( number > 0){
      result = "positive";
      ++npos;
    }
    else if( number < 0){
      result = "negative";
      ++nneg;
    }
    else{
      result = "zero";
    }

    return result;
}






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
