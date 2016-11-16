#include "vect2D.hh"
#include <istream>
#include <ostream>
#include <cmath>

double Vec_2D::length() const {
  return std::sqrt( x * x + y * y);
}


double length(const Vec_2D & a){
  return a.length();
}

Vec_2D & Vec_2D::operator+=(const Vec_2D & v){
  x += v.x;
  y += v.y;
  return *this;
}

Vec_2D & Vec_2D::operator*=(double a){
  x *= a;
  y *= a;
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
