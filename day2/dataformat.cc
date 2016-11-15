#include "dataformat.h"
#include <fstream>
#include <vector>
#include <string>

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
