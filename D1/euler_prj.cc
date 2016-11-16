#include <iostream>

#include <vector>
#include <string>
#include <map>


int main(int argc, char const *argv[]) {
  std::map<int, std::string> euler;
  euler[0] = "";
  euler[1] = "one";
  euler[2] = "two";
  euler[3] = "three";
  euler[4] = "four";
  euler[5] = "five";
  euler[6] = "six";
  euler[7] = "seven";
  euler[8] = "eight";
  euler[9] = "nine";
  euler[10] = "ten";
  euler[11] = "eleven";
  euler[12] = "twelve";
  euler[13] = "thirteen";
  euler[14] = "fourteen";
  euler[15] = "fiveteen";
  euler[16] = "sixteen";
  euler[17] = "seventeen";
  euler[18] = "eightteen";
  euler[19] = "nineteen";
  euler[20] = "twenty";
  euler[30] = "thirty";
  euler[40] = "fourty";
  euler[50] = "fifty";
  euler[60] = "sixty";
  euler[70] = "seventy";
  euler[80] = "eighty";
  euler[90] = "ninety";
  euler[100] = "hundred";
  euler[1000] = "thousand";

  for( auto e : euler){
    std::cout << e.first << ' ' << e.second << "\n";
  }

  int sum = 0;

  # RESULT 21124


    for(int i = 1; i < 20 ; i++){
      sum += euler[i].size();
    }

    for(int i = 20; i < 100; i+=10 )
      for(int j = 1; j < 10; j++){
        sum += euler[i].size() + euler[j].size();
      }



  std::cout << "Sum: " << sum << std::endl;
  std::cout << "Sum2: " << euler[0].size() << std::endl;

  /*
  euler[11] = "eleven";
  euler[12] = "twelve";
  euler[13] = "thirteen";
  euler[14] = "fourteen";
  euler[15] = "fiveteen";
  euler[16] = "sixteen";
  euler[17] = "seventeen";
  euler[18] = "eightteen";
  euler[19] = "nineteen";
  euler[20] = "twenty";
  euler[30] = "thirty";
  euler[40] = "fourty";
  euler[50] = "fifty";
  euler[60] = "sixty";
  euler[70] = "seventy";
  euler[80] = "eighty";
  euler[90] = "ninety";
  euler[100] = "hundred";
  euler[1000] = "thousand";
  */



  return 0;
}
