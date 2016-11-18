#include <string>
#include <iostream>
#include <memory>
#include <vector>

namespace Zoo {

class Animal {
private:
	unsigned int age_;
	std::string name_;

public:
	Animal(std::string name) 
		: age_(0), name_(name) 
	{}// std::cout << "Animal constructor for " << name << "!\n";	}

	Animal(const Animal & a) 
		: age_(a.age_), name_(a.name_) 
	{}// std::cout << "Animal copy constructor for " << a.name() << "!\n";	}




	virtual std::string sound() const
	{ 
	 	return "..."; 
	}




	unsigned int age() const { return age_; }
	std::string name() const { return name_; }

	void birthday() { age_ += 1; }
};






class Dog : public Animal {
private:
	std::string favouriteToy_;
public:
	Dog(std::string name, std::string toy) 
	    : Animal(name), favouriteToy_(toy) 
	    {}// std::cout << "Dog constructor for " << name << "!\n";	}

	std::string sound() const { 
		return "<< bark >>"; 
	}

	std::string favouriteToy() const { return favouriteToy_; }
};

class Crocodile : public Animal {
public:
	Crocodile(std::string name) 
	    : Animal(name)
	    {}

	// std::string sound() const { 
	// 	return "come fa?"; 
	// }
};

class NoisyCrocodile : public Crocodile {
public:
	NoisyCrocodile(std::string name) 
	    : Crocodile(name)
	    {}

	std::string sound() const { 
		return "<< roar >>"; 
	}
};



class Cat : public Animal {
private:
	std::string favouritePlace_;
public:
	Cat(std::string name, std::string place) 
	    : Animal(name), favouritePlace_(place) 
	    {}// std::cout << "Cat constructor for " << name << "!\n";	}

	std::string sound() const { 
		return "<< miaow >>"; 
	}

	std::string favouritePlace() const { 
		return favouritePlace_; 
	}
};


bool isYounger(const Animal & a, const Animal & b) {
	return a.age() < b.age();
}


bool sameSound(const Animal & a, const Animal & b) {
 	return a.sound() == b.sound();
}

using AnimalPtr = std::unique_ptr<Animal>;
using DogPtr = std::unique_ptr<Dog>;
using CatPtr = std::unique_ptr<Cat>;


}


Zoo::AnimalPtr makeAnimal(std::string type, std::string name, std::string stuff) {
	if ( type == "Dog" ) {
		return Zoo::DogPtr(new Zoo::Dog(name,stuff));
	}
	else if ( type == "Cat" ) {
		return Zoo::CatPtr(new Zoo::Cat(name,stuff));
	}
	return nullptr;
}


int main() {
	// Zoo::Animal foo("Thing");
	// std::cout << foo.name() << ' ' << foo.age() << '\n';
 //    std::cout << "=========\n";

	// Zoo::Crocodile bar("Pluto","Ball");
	// std::cout << bar.name() << ' ' << bar.age() << '\n';
	// bar.birthday();
	// std::cout << bar.name() << ' ' << bar.age() << '\n';
	// std::cout << bar.favouriteToy() << '\n';
 //    std::cout << "=========\n";
	
	// Zoo::Cat baz("Tom","Sofa");
	// std::cout << baz.name() << ' ' << baz.age() << '\n';
	// baz.birthday();
	// baz.birthday();
	// baz.birthday();
	// baz.birthday();
	// std::cout << baz.name() << ' ' << baz.age() << '\n';
	// std::cout << baz.favouritePlace() << '\n';
 //    std::cout << "=========\n";
	
	// std::cout 
	// 	<< std::boolalpha
	// 	<< isYounger(bar, baz) << ' '
	// 	<< isYounger(baz, bar)
	// 	<< '\n';

	//Zoo::Animal thingy("Thing"); // ?
	Zoo::Dog    doggy ("Doggy","Bone");
	Zoo::Cat    catty ("Catty","Sofa");
	Zoo::NoisyCrocodile croc("Croc");

	std::cout << "Original\n";
    //std::cout << thingy.sound() << '\n';
	std::cout <<  doggy.sound() << '\n';
	std::cout <<  catty.sound() << '\n';
	std::cout <<  croc.sound()  << '\n';

	//Zoo::Animal & tng_ref = thingy;
	Zoo::Animal & dog_ref = doggy;
	Zoo::Animal & cat_ref = catty;
	Zoo::Animal & croc_ref = croc;

	std::cout << "Reference\n";
    //std::cout << tng_ref.sound() << '\n';
	std::cout << dog_ref.sound() << '\n';
	std::cout << cat_ref.sound() << '\n';
	std::cout << croc_ref.sound() << '\n';


	// std::cout << dog_ref.sound() << '\n';
	// std::cout << cat_ref.sound() << '\n';




	std::vector<Zoo::AnimalPtr> vec;

	Zoo::DogPtr dogP(new Zoo::Dog("Pluto","Bone"));

	vec.push_back( std::move(dogP) );

	//std::cout << "Illegal: " << dogP->name() << '\n';

	vec.push_back( makeAnimal("Cat","Tom","Sofa") );
	
	vec.push_back(
	    Zoo::DogPtr(new Zoo::Dog("Barky","Ball"))
	);

	std::cout << "Loop:\n";
	for ( const auto & a : vec )
		std::cout << a->sound() << '\n';







	// // calls Animal copy constructor
	// Zoo::Animal dog_copy = doggy;
	// Zoo::Animal cat_copy = catty;
	// std::cout << dog_copy.sound() << '\n';
	// std::cout << cat_copy.sound() << '\n';





	return 0;
}





void printNameAndSound(const Zoo::Animal & a) {
	std::cout 
		<< a.name() << ' ' 
		<< a.sound() << '\n';
}



