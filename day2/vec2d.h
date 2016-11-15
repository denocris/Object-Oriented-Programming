// include guards necessary to avoid double inclusion
#ifndef VEC2D_H
#define VEC2D_H

// keep header dependencies in .h files to an absolute minimum

// iosfwd is just declaring the various IO classes.
// Implementations are in istream, ostream, iostrem and fstream
#include <iosfwd>

// class is private by default
// struct is public by default
// no other difference, they are interchangeable
class Vec_2D {

// private members ensure some internal consistency of the object
// you should never allow an object to exist with inconsistent state
private:
	// member variables
	int x_;
	int y_;
	double r_;
	double phi_;

	// private member function
	// not intended for external use
	void updateRandPhi();

public:
	// default constructor
	Vec_2D();
	// Constructor from x/y values
	Vec_2D(int x, int y);

	// accessors ("getters") for x and y. Note: const!
	// We don't want to allow changing the internal state
	int x() const { return x_; }
	int y() const { return y_; }

	// assume r and phi are expensive to calculate
	// if cheap to calculate, we could do the calculation here
	// and not bother with r_ and phi_
	double r() const { return r_; }
	double phi() const { return phi_; }

	double length() const;

	Vec_2D & operator+=(const Vec_2D &);

	Vec_2D & operator*=(const double);

	// Istream needs to be a friend, needs to write to the internals
	friend std::istream & operator>>(std::istream &, Vec_2D &);

	// do _not_ make ostream a friend, it can use x() and y()
};

// alternative length calculation as a free-standing function
double length(const Vec_2D & a);

// stream operations for Vec_2D
std::ostream & operator<<(std::ostream & os, const Vec_2D & v);
std::istream & operator>>(std::istream & is, Vec_2D & v);

// arithmetic operations for Vec_2D
// can provide more, but think if they make sense first!
Vec_2D operator+(const Vec_2D & a, const Vec_2D & b);
Vec_2D operator-(const Vec_2D & a, const Vec_2D & b);

// free-standing function for the distance between two objects.
// unlike length(), this should not be a member funtion. It doesn't
// naturally belong to one object or the other
double distance(const Vec_2D & a, const Vec_2D & b);


#endif
