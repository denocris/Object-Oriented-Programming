#ifndef __STATION__hh__
#define __STATION__hh__

#include "luggage.hh"
#include <map>
#include <string>
#include <vector>

using Destination = std::string;

class Station{

public:

 //Station();

 std::vector<Luggage> data;

 std::vector<Destination> destinations;  //  {A, B ,C}

 std::map< Destination, std::vector<Luggage> > dest_schedule;

 void schedule(std::vector<Luggage> data);

};

#endif
