#ifndef __LUGG__hh__
#define __LUGG__hh__

#include <string>
#include <iostream>
#include <vector>
#include <fstream>


class Luggage {

public:
	std::string label;
	double weight;
	std::string dest;

};


std::vector<Luggage> read_file(std::string file);

#endif
