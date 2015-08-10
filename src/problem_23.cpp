// https://projecteuler.net/problem=23
// Michael Seyfert <michael@codesand.org>
/*
Problem Statement:

A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
*/

/*
My solution is fairly slow. Just seive, seive, seive.
 */
#include <vector>
#include <iostream>
using namespace std;

static const int N = 28123;
// We can check our result by increasing N,
// the result should not change.
// static const int N = 28123*2;

int main()
{
	vector<vector<int> > divisors(N);
	vector<int> abundants;

	// The problem tells us that the greatest number
	// that cannot be expressed as the sum of two abundant numbers is less
	// than N. So we only need to check these.
	for(int d = 1;d < N-1;++d)
		for(int k = d+1;k < N;++k)
			if(k % d == 0)
				divisors[k].push_back(d);

	for(size_t k = 0;k < divisors.size();++k) {
		// cout << "divisors of " << k << ':';
		size_t s = 0;
		for(size_t j = 0;j < divisors[k].size();++j)
			s += divisors[k][j];
		// 	cout << ' ' << divisors[k][j];
		// cout << '\n';
		if(s > k) abundants.push_back(k);
	}

	vector<bool> sum_pair(N,false);
	for(size_t k = 0;k < abundants.size();++k)
		for(size_t j = k;j < abundants.size();++j){
			int sum = abundants[k] + abundants[j];
			if(sum >= N)
				break; // We will only get larget abundants[j].
			sum_pair[sum] = true;
		}

	size_t result = 0;
	for(size_t k = 1;k < sum_pair.size();++k)
		if(!sum_pair[k]){
			// 20161 is the largest number which cannot be expressed
			// as the sum of two abundant numbers.
			// cout << k << '\n';
			result += k;
		}
	cout << result << '\n';
}
