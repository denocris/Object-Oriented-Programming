#ifndef __STATION__hh__
#define __STATION__hh__

#include "passenger.hh"
#include "aircraft.hh"

#include <map>
#include <string>
#include <vector>

using Destination = std::string;

class Airport{

public:

 //Station();

 std::vector<Passenger> data;
 std::vector<Destination> destinations;  //  {A, B ,C}
 std::map< Destination, std::vector<Passenger> > dest_schedule;


 void schedule(std::vector<Passenger> data);
 double passengers_weight_to_dest(std::string dest);
 Plane & choose_the_right_plane(Destination dest, Cessna & a, ATR & b, Boeing & c);



};

#endif
