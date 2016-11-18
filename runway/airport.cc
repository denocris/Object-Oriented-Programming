#include <map>
#include "airport.hh"


void Airport::schedule(std::vector<Passenger> data){

for (auto line : data){
	destinations.push_back(line.dest);

	sort( destinations.begin(), destinations.end() );

	destinations.erase( unique( destinations.begin(), destinations.end() ), destinations.end() );

	dest_schedule[line.dest].push_back(line);
}
}
