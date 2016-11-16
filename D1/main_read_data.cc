#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>


struct DataLine{
  int x1;
  int y1;

  int x2;
  int y2;
};

//double distance(int x1, int y1, int x2, int y2){
double distance(const DataLine & line){
  const int dx = line.x2 - line.x1;
  const int dy = line.y2 - line.y1;
  return std::sqrt( dx * dx + dy * dy );
}

std::vector<DataLine> read_data(std::string file){
  std::vector<DataLine> data;
  std::ifstream input(file);

  int a, b, c, d;
  while( input >> a >> b >> c >> d ){

    data.push_back( {a, b, c, d} );
  }

  input.close();
  return data;
}



int main(){

  std::vector<DataLine> data = read_data("tmp.data");


  std::cout << data.size() << '\n';

  for( auto line : data){
    std::cout
     << "(" << line.x1 << " "
            << line.y1 << ") "
     << "(" << line.x2 << ' '
            << line.y2 << ") ==>"
    << distance(line) << std::endl;

  }


}
