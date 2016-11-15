#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>

struct Vec_2D {
	int x;
	int y;
};




std::ostream & operator<<(std::ostream & os,
                          const Vec_2D & v) {
	os << '(' << v.x << ',' << v.y << ')';
	return os;
}

std::istream & operator>>(std::istream & is,
                          Vec_2D & v) {
	is >> v.x >> v.y;
	return is;
}




Vec_2D operator+(const Vec_2D & a, const Vec_2D & b) {
	return {a.x + b.x, a.y + b.y};
}

Vec_2D operator-(const Vec_2D & a, const Vec_2D & b) {
	return {a.x - b.x, a.y - b.y};
}




// provide more math operators

double length(const Vec_2D & a) {
	return std::sqrt( a.x*a.x + a.y*a.y );
}

double distance(const Vec_2D & a, const Vec_2D & b) {
	return length( b - a );
}

struct DataLine { 
	Vec_2D a;
	Vec_2D b;
};


std::vector<DataLine> readData(std::string filename) {
	std::ifstream input("tmp.data");
	std::vector<DataLine> data;
	Vec_2D a,b;
	while ( input >> a >> b ) {
		data.push_back( {a,b} );
	}
	input.close();
	return data;
}

int main() {
	std::vector<DataLine> data = readData("tmp.data");

	std::cout << data.size() << '\n';

	for ( auto line : data ) {
		std::cout 
		    << line.a
		    << ' '
		    << line.b
			<< " ==> "
			<< distance(line.a, line.b) << std::endl;
	}
}
