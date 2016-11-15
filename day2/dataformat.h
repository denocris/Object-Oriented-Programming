#ifndef DATAFORMAT_H
#define DATAFORMAT_H

#include "vec2d.h"
#include <string>
#include <vector>

struct DataLine { 
	Vec_2D a;
	Vec_2D b;
};

std::vector<DataLine> readData(std::string filename);

#endif
