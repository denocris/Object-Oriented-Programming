#include <iostream>
#include <cmath>



class Vec_2D{
private:

  double x_;
  double y_;

  double r_;
  double phi_;

public:
  Vec_2D();
  Vec_2D(double x1, double y1 );

  double length() const;

  double r() const {return r_;};
  double phi() const {return phi_;};

  int x() const {return x_; };
  int y() const {return y_; };

  Vec_2D & operator+=(const Vec_2D &);
  Vec_2D & operator*=(const double);

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
