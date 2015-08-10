// https://projecteuler.net/problem=7
// Michael Seyfert <michael@codesand.org>
/*
Problem Statement:

By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?

*/

#include<iostream>
using namespace std;

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
	const size_t N = 10001;
	size_t current = 0;
	size_t p;
	for(p = 2; current < N; ++p)
		if(IsPrime(p))
			++current;
	cout << p-1 << '\n';
}
