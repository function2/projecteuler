// https://projecteuler.net/problem=1
// Michael Seyfert <michael@codesand.org>
/*
Problem Statement:

If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.

 */

#include<iostream>
using namespace std;

// static const int MULT_BELOW = 10; // Test: should get 23.
static const size_t MULT_BELOW = 1000;

int main()
{
	size_t sum = 0;
	for(size_t k = 3;k < MULT_BELOW;++k)
		if(!(k % 3) || !(k % 5))
			sum += k;
	cout << sum << '\n';
}
