#include "luggage.hh"


std::vector<Luggage> read_file(std::string file) {

    std::vector<Luggage> data;
    std::ifstream input(file);
	std::string a;
	double b;
	std::string c;
    while (input >> a >> b >> c) {
         data.push_back({a, b, c});
    }
    input.close();
    return data;
}
