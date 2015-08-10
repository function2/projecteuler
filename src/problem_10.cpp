// https://projecteuler.net/problem=10
// Michael Seyfert <michael@codesand.org>
/*
Problem Statement:

The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.

Note: I expect a 64 bit architecture for this problem.
otherwise use libgmp like in problem 8.
*/

#include<iostream>
using namespace std;

// There is certainly a faster way to do this!
// You could do a sieve.
bool IsPrime(size_t n)
{
	if(n <= 1) return false;
	if(n == 2) return true;
	if(!(n % 2)) return false;
	for(size_t k = 3;k*k <= n;k+=2)
		if(!(n % k)) return false;
	return true;
}

int main()
{
	//const size_t N = 10;
	const size_t N = 2e6;

	size_t sum = 0;
	for(size_t k = 2;k < N;++k)
		if(IsPrime(k))
			sum += k;
	cout << sum << '\n';
}
