#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "a2.h"
using std::string;
using std::vector;
using std::cout;
using std::endl;

void prime_exists(vector<int> v, int potentialPrime)
{
	std::vector<int>::iterator it;
	it = find(v.begin(), v.end(), potentialPrime);
    if(it != v.end()){
		cout << "Number is a prime!" << endl;
	}
	else{
		cout << "number is NOT a prime!" << endl;
	}
}
int main()
{
    Primate p;
	cout << "Printing all primes, between 0 and 200, also the biggest prime smaller than 100000" << endl;
    p.printPrimes(cout, 200);
    p.printBiggestPrime(cout);		
	cout << "Printing done\n" << endl;

	cout << "------Testing primes-------" << endl;
	std::vector<int> primes = p.getPrimes();
	prime_exists(primes, 8807);
	prime_exists(primes, 10663);
	prime_exists(primes, 92899);
	prime_exists(primes, 61381);
	cout << "--------Testing non primes------" << endl;
	prime_exists(primes, 5536);
	prime_exists(primes, 6769);
	prime_exists(primes, 3546);
	prime_exists(primes, 25378);
	
	cout << "-----------Testing done---------" << endl;
	
    return 0;
}