#include "vec2d.h"
#include "dataformat.h"
#include <vector>
#include <iostream>

int main() {
	std::vector<DataLine> data = readData("tmp.data");

	std::cout << data.size() << '\n';

	for ( auto line : data ) {
		std::cout 
		    << line.a 
		    << ' ' 
		    << line.b 
		    << " ==> "
			<< distance(line.a, line.b) 
			<< std::endl;
	}
}
