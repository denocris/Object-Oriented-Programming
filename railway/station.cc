#include <map>
#include "station.hh"


void Station::schedule(std::vector<Luggage> data){

for (auto line : data){
		destinations.push_back(line.dest);

		sort( destinations.begin(), destinations.end() );

		destinations.erase( unique( destinations.begin(), destinations.end() ), destinations.end() );

	  dest_schedule[line.dest].push_back(line);
}
}
