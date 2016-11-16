#include "vect2D.hh"
#include <istream>
#include <ostream>
#include <cmath>

void Vec_2D::updateRandPhi();


double Vec_2D::length() const {
  return std::sqrt( x * x + y * y);
}

double Vec_2D::phi() const {
  return std::atan2(y,x);
}

Vec_2D::Vec_2D(){
  x_ = 0;
  y_ = 0;
  r_ = 0;
  phi_ = 0;
}

Vec_2D::Vec_2D(double x, double y){
  x_ = x;
  y_ = y;
  r_ = length();
  phi_ = std::atan2(y,x);
}


double length(const Vec_2D & a){
  return a.length();
}

Vec_2D & Vec_2D::operator+=(const Vec_2D & v){
  x_ += v.x;
  y_ += v.y;
  r_ = length();
  phi_ = std::atan2(y,x);
  return *this;
}

Vec_2D & Vec_2D::operator*=(double a){
  x_ *= a;
  y_ *= a;
  r_ *= a;
  return *this;
}



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


double distance(const Vec_2D & a, const Vec_2D & b){
  return length( b - a );
}
