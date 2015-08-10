// https://projecteuler.net/problem=21
// Michael Seyfert <michael@codesand.org>
/*
Problem Statement:

Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.

 */
#include <map>
#include <iostream>
using namespace std;

template<typename numtype>
numtype GetSumDivisors(numtype n)
{
	// Start with a simple slow solution, which
	// is probably faster than dealing with prime factors anyway.
	numtype total = 0;
	for(int k = 1;k < n;++k)
		if(n % k == 0)
			total += k;
	return total;
}

int main()
{
	map<int,int> d;
	int result = 0;
	for(int k = 2; k < 10000; ++k){
		// Check if two numbers have the same divisor sum.
		// if(d[k] != 0) return EXIT_FAILURE;
		// result: all numbers [2,10000) map to a unique divisor sum.

		int s = GetSumDivisors(k);
		if(d[s] == k){
			// Only the largest of the two 'amicable numbers'
			// will end up here. Count them both.
			result += k + s;
		}
		d[k] = s;
	}
	cout << result << '\n';
}
