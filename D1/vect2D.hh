#include <iostream>
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

Vec_2D operator+(const Vec_2D & a, const Vec_2D & b);

Vec_2D operator-(const Vec_2D & a, const Vec_2D & b);

Vec_2D operator*(double c, const Vec_2D & a);

Vec_2D operator/(double c, const Vec_2D & a);

std::istream & operator>>(std::istream & is, Vec_2D & v);

std::ostream & operator<<(std::ostream & os, const Vec_2D & v);

double operator*(const Vec_2D & a, const Vec_2D & b);

double length(const Vec_2D & a);

double distance(const Vec_2D & a, const Vec_2D & b);
