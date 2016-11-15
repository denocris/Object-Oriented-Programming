#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>

struct Point {
	int x;
	int y;
};

Point subtract(const Point & a, const Point & b) {
	return {b.x - a.x, b.y - a.y};
}

double distTo0(const Point & a) {
	return std::sqrt( a.x*a.x + a.y*a.y );
}

double distance(const Point & a, const Point & b) {
	return distTo0( subtract(a,b) );
}

struct DataLine { 
	Point a;
	Point b;
};


std::vector<DataLine> readData(std::string filename) {
	std::ifstream input("tmp.data");
	std::vector<DataLine> data;
	int a,b,c,d;
	while ( input >> a >> b >> c >> d ) {
		data.push_back( {{a,b},{c,d}} );
	}
	input.close();
	return data;
}

int main() {
	std::vector<DataLine> data = readData("tmp.data");

	std::cout << data.size() << '\n';

	for ( auto line : data ) {
		std::cout 
			<< "(" << line.a.x << " " 
			       << line.a.y << ") "
			<< "(" << line.b.x << " " 
			       << line.b.y << ") ==> "
			<< distance(line.a, line.b) << std::endl;
	}
}
