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

Cessna C172;
ATR Atr42;
Boeing B737;

for (auto dest : RonchiDeiLegionari.destinations){

	Plane & chosen_plane = RonchiDeiLegionari.choose_the_right_plane(dest, C172, Atr42, B737);

	chosen_plane.give_plane_destination(dest); // it assign the destination of the train

	chosen_plane.load_passengers(RonchiDeiLegionari.dest_schedule, dest);

	chosen_plane.let_plane_depart();  // Let the train depart
}

return 0;

}
