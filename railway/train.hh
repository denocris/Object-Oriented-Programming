#ifndef __TRAIN__hh__
#define __TRAIN__hh__

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include "luggage.hh"


class Train{

	private:

		std::string dest_;
		std::string status_ = "Not Ready";  
		double weight_;

	public:

		std::string dest() {return dest_;}

		std::string  status() {return status_;}

		double weight(){return weight_;}

		void give_train_destination(std::string destination); // where the train should go

		double load_luggages(std::map<std::string,std::vector<Luggage>> dest_schedule, std::string dest); // loading function

		void let_train_depart();
};

#endif
