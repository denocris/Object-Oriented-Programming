#include "sign_hello.hh"

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
