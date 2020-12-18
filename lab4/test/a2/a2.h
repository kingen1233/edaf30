#ifndef A2_H
#define A2_H

#include <string>
#include <iostream>
#include <iterator>
#include <vector>

class Primate {
public:
	Primate();
	void printPrimes(std::ostream& out, int amnt) const;
	void printBiggestPrime(std::ostream& out) const;
	int getBiggestPrime() const;
	std::vector<int> getPrimes() const;
	
	
private:
	void primate();
    std::string primes;	
	std::vector<int> v;
};

#endif
