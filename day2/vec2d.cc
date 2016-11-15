#include "vec2d.h"
#include <istream>
#include <ostream>
#include <cmath>

void Vec_2D::updateRandPhi() {
	r_ = length();
	phi_ = std::atan2(y_,x_);
}

Vec_2D::Vec_2D() {
	x_ = 0;
	y_ = 0;
	updateRandPhi();
}

Vec_2D::Vec_2D(int x, int y) {
	x_ = x;
	y_ = y;
	updateRandPhi();
}


double Vec_2D::length() const {
	return std::sqrt( x_ * x_  +  y_ * y_ );
}

Vec_2D & Vec_2D::operator+=(const Vec_2D & v) {
	x_ += v.x();
	y_ += v.y();
	updateRandPhi();
	return *this;
}

Vec_2D & Vec_2D::operator*=(const double a) {
	x_ *= a;
	y_ *= a;
	updateRandPhi();
	return *this;
}


double length(const Vec_2D & a) {
	return a.length();
}




std::ostream & operator<<(std::ostream & os, 
                          const Vec_2D & v) {
	os << '(' << v.x() << ',' << v.y() << ')';
	return os;
}

std::istream & operator>>(std::istream & is, 
                          Vec_2D & v) {
	is >> v.x_ >> v.y_;
	v.updateRandPhi(); // don't forget this!
	return is;
}

Vec_2D operator+(const Vec_2D & a, const Vec_2D & b) {
	return {a.x() + b.x(), a.y() + b.y()};
}

Vec_2D operator-(const Vec_2D & a, const Vec_2D & b) {
	return {a.x() - b.x(), a.y() - b.y()};
}

double distance(const Vec_2D & a, const Vec_2D & b) {
	return length( b - a ); // or (b-a).length()
}
