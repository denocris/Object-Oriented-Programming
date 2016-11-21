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

double Airport::passengers_weight_to_dest(std::string dest){
	double sum = 0;
	for (auto i : dest_schedule){
		//std::cout << i.first << std::endl;
			if (i.first == dest){
				for(int j=0; j < i.second.size(); j++)
				{
				//std::cout << i.first << " " <<i.second[0].weight << " " <<i.second[1].weight << std::endl;
				sum += i.second[j].weight;
			}
			}
	}
	//std::cout << sum << std::endl;
	return sum;
}


Plane & Airport::choose_the_right_plane(std::string dest, Cessna & a, ATR & b, Boeing & c){

	double dest_weight = passengers_weight_to_dest(dest);

	if( dest_weight < 50.0){
		std::cout << "Cessna 172" << std::endl;
		return a;
	}
	else if(dest_weight > 50 && dest_weight < 100){
		std::cout << "Atr 42" << std::endl;
		return b;
	}
	else
	std::cout << "Boeing 737" << std::endl;
	return c;

}
