#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>


struct Vec_2D{
  int x;
  int y;
};

struct DataLine{
  Vec_2D a;
  Vec_2D b;
};

Vec_2D subtract(const Vec_2D & a, const Vec_2D & b){
  return {a.x - b.x, a.y - b.y};
}

double distTo0(const Vec_2D & a){
  return std::sqrt(a.x * a.x + a.y * a.y);
}

double distance(const Vec_2D & a, const Vec_2D & b){
  return distTo0( subtract(a,b) );
}

std::vector<DataLine> read_data(std::string file){
  std::vector<DataLine> data;
  std::ifstream input(file);

  int a, b, c, d;
  while( input >> a >> b >> c >> d ){

    data.push_back( {{a, b}, {c, d}} );
  }

  input.close();
  return data;
}



int main(){

  std::vector<DataLine> data = read_data("tmp.data");


  std::cout << data.size() << '\n';

  for( auto line : data){
    std::cout
     << "(" << line.a.x << " "
            << line.a.y << ") "
     << "(" << line.b.x << ' '
            << line.b.y << ") ==>"
    << distance(line.a, line.b) << std::endl;

  }


}
