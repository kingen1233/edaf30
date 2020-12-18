#include "a2.h"
using std::cin;
using std::cout;
using std::endl;

Primate::Primate()
{
    primes = "CC";
    for (auto i = 2; i < 100000; i++)
    {
        primes.append("P");
    }
    primate();

    std::string p = primes;
    while (p.find("P") != std::string::npos)
    {
        auto nextPrime = p.find("P");
        // Replace so we dont find the same one everytime
        p.replace(nextPrime, 1, "C");
        v.push_back(nextPrime);
    }  
}

void Primate::primate()
{
    for (auto i = 2; i < 100000; i++)
    {
        int sum = i;
        while (sum < 100000)
        {
            sum += i;
            if (sum >= 100000)
                break;
            primes.replace(sum, 1, "C");
        }
    }
}

void Primate::printPrimes(std::ostream &out, int amnt) const
{
    for(int i = 0; i < amnt; i++){
        auto nextPrime = v[i];
        if(nextPrime <= amnt){
            out << nextPrime << endl;
        }
        else{
            break;
        }
    }
   
}

void Primate::printBiggestPrime(std::ostream&out) const {
    out <<  "Biggest prime: " << primes.rfind("P") << endl;
}

std::vector<int> Primate::getPrimes() const {
    return v;
}
