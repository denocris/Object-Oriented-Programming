#ifndef __TRAIN__hh__
#define __TRAIN__hh__

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include "passenger.hh"


class Aircraft{

	private:

		std::string dest_;
		std::string status_ = "Not Ready";  // status_ can become "Ready"
		double weight_;

	public:

		std::string dest() {return dest_;}

		std::string  status() {return status_;}

		double weight(){return weight_;}

		void give_aircraft_destination(std::string destination); // where the train should go

		double load_passengers(std::map<std::string,std::vector<Passenger>> dest_schedule, std::string dest); // loading function

		void let_aircraft_depart();
};

#endif
