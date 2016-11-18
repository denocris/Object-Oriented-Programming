#ifndef __LUGG__hh__
#define __LUGG__hh__

#include <string>
#include <iostream>
#include <vector>
#include <fstream>


class Passenger {

public:
	std::string label;
	double weight;
	std::string dest;

};


std::vector<Passenger> read_file(std::string file);

#endif
