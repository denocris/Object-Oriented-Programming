#include <iostream>
#include <string>

std::string sign(int n, int & npos, int & nneg) {
	std::string result;
	if ( n > 0 ) {
		result = "positive";
		++npos;
	}
	else if ( n < 0 ) {
		result = "negative";
		++nneg;
	}
	else {
		result = "zero";
	}
	return result;
}







int main() 
{
	int repeats;
	std::cout << "How many repeats? ";
	std::cin >> repeats;

	int npos = 0;
	int nneg = 0;

	for ( int i=0; i < repeats; ++i ) {
		std::cout << "Write a number: ";

		int n;
		std::cin >> n;

		std::cout << n << " is "
				  << sign(n, npos, nneg)
				  << std::endl;
	}

	std::cout << "Saw " << npos << " positives and "
			  << nneg << " negatives" << std::endl;

	return 0;
}









