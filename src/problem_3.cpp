// https://projecteuler.net/problem=3
// Michael Seyfert <michael@codesand.org>
/*
Problem Statement:

The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?

 */
// With 64 bit registers this problem is very simple.
#include <iostream>
#include <vector>
using namespace std;

typedef long num;

//static const size_t N = 13195;
static const num N = 600851475143L;

template<typename numtype>
bool IsPrime(numtype n)
{
	if(n <= 1) return false;
	if(n == 2) return true;
	if(!(n % 2)) return false;
	for(numtype k = 3;k*k <= n;k+=2)
		if(!(n % k)) return false;
	return true;
}

template<typename numtype>
void GetPrimeFactors(std::vector<numtype> &pfactors,numtype n)
{
	pfactors.clear();

	for(numtype k = 2;n > 1;++k)
		if(IsPrime(k)){
			while(!(n % k)){
				n /= k;
				pfactors.push_back(k);
			};
		}
}

int main(int argc, char **argv)
{
	vector<num> factors;
	GetPrimeFactors(factors, N);
	cout << *(factors.end()-1) << '\n';
}
