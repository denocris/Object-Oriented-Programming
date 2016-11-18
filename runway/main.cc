#include "passenger.hh"
#include "airport.hh"
#include "aircraft.hh"

int main(){

/*

This is a program to schedule flights with Cristiano ;-)

*/

// Accra: Capital of Ghana!
Airport RonchiDeiLegionari;

// We need to read our file and put it in data
RonchiDeiLegionari.data = read_file("passenger.dat");

// We need to fill the destinations and dest_schedule vectors
RonchiDeiLegionari.schedule(RonchiDeiLegionari.data);

// Now we are ready to create trains, give them a dest, load them and let them depart
for (auto dest : RonchiDeiLegionari.destinations){

// Choose your favourite aircraft to fly with Cristiano

	Aircraft Cessna172;

	Cessna172.give_aircraft_destination(dest); // it assign the destination of the train

	Cessna172.load_passengers(RonchiDeiLegionari.dest_schedule, dest);

	Cessna172.let_aircraft_depart();  // Let the train depart
}

return 0;

}
