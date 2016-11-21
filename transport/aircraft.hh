#ifndef __TRAIN__hh__
#define __TRAIN__hh__

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include "passenger.hh"

class Plane {

	private:
		std::string dest_ = "";
		std::string status_ = "Not Ready";  // status_ can become "Ready"
		double weight_ = 0.0;
	public:
		std::string dest() const {return dest_;}
		std::string  status() const {return status_;}
		double weight() const {return weight_;}



	virtual void give_plane_destination(std::string destination);
	virtual double load_passengers(std::map<std::string,std::vector<Passenger>> dest_schedule, std::string dest); // loading function
	virtual void let_plane_depart();

	virtual double max_weight() const = 0;
};


class Cessna : public Plane {
	private:
	const double MAXWT = 50.0;

	public:
	virtual double max_weight() const {
		return MAXWT;
	}
};

class ATR : public Plane {
	private:
	const double MAXWT = 100.0;

	public:
	virtual double max_weight() const {
	return MAXWT;
	}
};

class Boeing : public Plane {
	private:
	const double MAXWT = 200.0;

	public:
	virtual double max_weight() const {
	return MAXWT;
	}
};





#endif
