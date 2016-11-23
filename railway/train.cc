#include "train.hh"
#include "luggage.hh"


void Train::give_train_destination(std::string destination){
    dest_ = destination;
    status_ = "Ready to Load";
}

double sum_tot_weight(std::vector<Luggage> luggage){
		double sum = 0;
		for (auto lug : luggage){
			sum += lug.weight;
		}
		return sum;
}

double Train::load_luggages(std::map<std::string,std::vector<Luggage>> dest_schedule, std::string dest){
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

void Train::let_train_depart(){
  if(status_ == "Ready to Depart")
	std::cout << "It's going to " << dest() << ", with a total weight of" << weight() << "Kg of potatos!" << std::endl;
}
