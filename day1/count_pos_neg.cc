#include <iostream>
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

		if ( n > 0 ) {
			std::cout << n << " is positive\n";
			++npos;
		}
		else if ( n < 0 ) {
			std::cout << n << " is negative\n";
			++nneg;
		}
		else {
			std::cout << n << " is zero\n";
		}
	}

	std::cout << "Saw " << npos << " positives and "
			  << nneg << " negatives" << std::endl;

	return 0;
}
