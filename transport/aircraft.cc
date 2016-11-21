#include "aircraft.hh"
#include "passenger.hh"


void Plane::give_plane_destination(std::string destination){
    dest_ = destination;
    status_ = "Ready to Load";
}

double sum_tot_weight(std::vector<Passenger> luggage){
		double sum = 0;
		for (auto lug : luggage){
			sum += lug.weight;
		}
		return sum;
}

double Plane::load_passengers(std::map<std::string,std::vector<Passenger>> dest_schedule, std::string dest){
	double sum = 0;
	if (status_ == "Ready to Load"){
		for (auto i : dest_schedule){
			if (i.first == dest){
				sum += sum_tot_weight(i.second);
			}
		}
	weight_ = sum;
	status_ = "Ready to Depart";
	}
	return sum;
}

void Plane::let_plane_depart(){
  if(status_ == "Ready to Depart")
	std::cout << "Runway 27, Cleared for take off to" << dest() << ", with a total weight of" << weight() << "Kg. Enjoy the flight!" << std::endl;
}
