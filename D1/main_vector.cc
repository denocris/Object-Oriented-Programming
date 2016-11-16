#include <iostream>

#include <vector>
#include <string>
#include <map>


void vect_add(const std::vector<int> &vect_1,
              const std::vector<int> &vect_2,
              std::vector<int> &vect_sum){

      vect_sum.resize(vect_1.size());
      for(int i = 0; i < vect_sum.size(); i++){

        vect_sum[i] = vect_1[i] + vect_2[i];
      }
}

int main(){

  std::vector<int> vec;

  std::cout << "size: " << vec.size() << "\n";
  vec.push_back(7);
  std::cout << "size: " << vec.size() << "\n";
  vec.push_back(3);
  std::cout << "size: " << vec.size() << "\n";

  std::cout << vec[0] << ' ' << vec[1] << "\n";

/*
// the two below for-loop are the same

  for( std::vector <int>::iterator it = vec.begin(); it < vec.end(); ++it ){
    std::cout << *it;
  }

  for( unsigned int i = 0; i < vec.size(); i++ ){
    std::cout << vec[i];
  }

// from C++ on

  for(auto it = vec.begin(); it < vec.end(); ++it){
    std::cout << *it;
  }

*/

std::vector<int> v1 = {1,2,3};
std::vector<int> v2 = {4,5,6};
std::vector<int> sum;

vect_add(v1, v2, sum);

for(int i : sum){
  std::cout<< i << "\n";
}

std::map < std::string, int> ages;

ages["Cessna"] = 172;
ages["Piper"] = 28;
ages["ask"] = 21;

for( auto e : ages){
  std::cout << e.first << ' ' << e.second << "\n";
}

ages.insert({"Maule", 01});

for( auto e : ages){
  std::cout << e.first << ' ' << e.second << "\n";
}


  return 0;
}
