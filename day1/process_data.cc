#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

struct Point {
	int x;
	int y;
};

struct DataLine { 
	Point a;
	Point b;
};

double distance(const Point & a, const Point & b) {
	const int dx = b.x - a.x;
	const int dy = b.y - a.y;
	return std::sqrt( dx*dx + dy*dy );
}

int main() {
	std::vector<DataLine> data;

	std::ifstream input("tmp.data");

	int a,b,c,d;

	while ( input >> a >> b >> c >> d ) {
		data.push_back( {{a,b},{c,d}} );
	}

	input.close();

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
