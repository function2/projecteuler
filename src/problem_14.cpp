// https://projecteuler.net/problem=14
// Michael Seyfert <michael@codesand.org>
/*
Problem Statement:

The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:
13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1

It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.

*/
#include <map>
#include <iostream>
using namespace std;

long GetLongest(long n)
{
	if(n == 1) return 1;

	static map<long,long> memo;

	map<long,long>::iterator I = memo.find(n);
	if(I != memo.end())
		return I->second;

	long longest;
	if(n % 2 == 0) // even
		longest = 1 + GetLongest(n/2);
	else // odd
		longest = 1 + GetLongest(3*n + 1);

	return memo[n] = longest;
}

int main()
{
	long start = 0;
	long longest = 0;
	// We can assume all these are going to finish at 1.
	for(size_t k = 2;k < 1e6;++k){
		long t = GetLongest(k);
		if(t > longest){
			longest = t;
			start = k;
		}
	}
	cout << start << '\n';
}
