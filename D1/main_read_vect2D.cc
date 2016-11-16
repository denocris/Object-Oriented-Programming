#include <iostream>
#include <fstream>
#include "vect2D.hh"
#include <vector>



std::vector<DataLine> read_data(std::string file){
  std::vector<DataLine> data;
  std::ifstream input(file);

  Vec_2D a, b;
  while( input >> a >> b ){

    data.push_back( {a, b} );
  }

  input.close();
  return data;
}



int main(){

  std::vector<DataLine> data = read_data("tmp.data");


  std::cout << data.size() << '\n';

  for( auto line : data){
    // std::cout
    //  << "(" << line.a.x << " "
    //         << line.a.y << ") "
    //  << "(" << line.b.x << ' '
    //         << line.b.y << ") ==>"
    ((std::cout << line.a) << ' ') << line.b
    << " ==> "
    << distance(line.a, line.b) << std::endl;

  }


}
