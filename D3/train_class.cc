#include <iostream>
#include <fstream>
#include <vector>

class Luggage {
  public:
    std::string luggage_label;
    double luggage_weight;
    std::string destination;

};

class Train {
  public:
  double tot_weight( std::vector l ) const;
  std::string dest() const;

  private:
  std::string destination;
  std::vector<Luggage> load;
};

double Train::tot_weight(std::vector l){
  double sum = 0;
  for(int i = 0; i < l.size(); i++){
    sum += load.luggage_weight;
  }
}

/*
class Station {
  public:

  private:

};
*/

int main(int argc, char const *argv[]) {


    std::vector<Luggage> data;
    std::ifstream input("luggage.dat");

    std::string a;
    double b;
    std::string c;
    while( input >> a >> b >> c ){

      data.push_back( {a, b, c} );
    }
    input.close();


  for( auto line : data){
    std::cout
     << line.luggage_label << " " << line.luggage_weight << " " << line.destination << std::endl;
   }

  return 0;

}
