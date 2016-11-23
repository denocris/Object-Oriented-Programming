#include "luggage.hh"
#include "station.hh"
#include "train.hh"

int main(){


// Accra: Capital of Ghana!
Station Accra;

// We need to read our file and put it in data
Accra.data = read_file("luggage.dat");

// We need to fill the destinations and dest_schedule vectors
Accra.schedule(Accra.data);

// Now we are ready to create trains, give them a dest, load them and let them depart
for (auto dest : Accra.destinations){

	Train train;

	train.give_train_destination(dest); // it assign the destination of the train

	train.load_luggages(Accra.dest_schedule, dest);

	train.let_train_depart();  // Let the train depart
}

return 0;

}
