#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>


struct Vec_2D{
  double x;
  double y;
};

struct DataLine{
  Vec_2D a;
  Vec_2D b;
};

Vec_2D operator+(const Vec_2D & a, const Vec_2D & b){
  return {a.x + b.x, a.y + b.y};
}

Vec_2D operator-(const Vec_2D & a, const Vec_2D & b){
  return {a.x - b.x, a.y - b.y};
}

Vec_2D operator*(double c, const Vec_2D & a){
  return {c * a.x,c * a.y };
}

Vec_2D operator/(double c, const Vec_2D & a){
  return { a.x / c, a.y / c };
}

std::istream & operator>>(std::istream & is, Vec_2D & v){
  is >> v.x >> v.y;
  return is;
}

std::ostream & operator<<(std::ostream & os, const Vec_2D & v){
  os << '(' << v.x << '|' << v.y << ')';
  return os;
}

double operator*(const Vec_2D & a, const Vec_2D & b){
  return a.x * b.x + a.y * b.y;
}

double length(const Vec_2D & a){
  return std::sqrt(a * a);
}

double distance(const Vec_2D & a, const Vec_2D & b){
  return length( b - a );
}

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
