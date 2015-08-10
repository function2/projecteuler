// https://projecteuler.net/problem=27
// Michael Seyfert <michael@codesand.org>
/*
Problem Statement:

Euler discovered the remarkable quadratic formula:

n² + n + 41

It turns out that the formula will produce 40 primes for the consecutive values n = 0 to 39. However, when n = 40, 402 + 40 + 41 = 40(40 + 1) + 41 is divisible by 41, and certainly when n = 41, 41² + 41 + 41 is clearly divisible by 41.

The incredible formula  n² − 79n + 1601 was discovered, which produces 80 primes for the consecutive values n = 0 to 79. The product of the coefficients, −79 and 1601, is −126479.

Considering quadratics of the form:

    n² + an + b, where |a| < 1000 and |b| < 1000

    where |n| is the modulus/absolute value of n
    e.g. |11| = 11 and |−4| = 4

Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n = 0.
*/

/*
We are given two good examples for this problem to check your code.
 */
#include<cmath>
#include<vector>
#include<iostream>
using namespace std;

int main()
{
	// Do a prime seive.
	static const int N = 1000000;
	vector<bool> prime(N,true);
	prime[0] = prime[1] = false;
	int root = int(floor(sqrt(N)));
	for(int k = 2;k <= root;++k)
		for(int j = k*2;j < N; j += k)
			prime[j] = false;

	// First solution, brute force:
	int best_streak = 0;
	int best_a=-1000;
	int best_b=-1000;
	for(int a = -999; a < 1000; ++a)
		for(int b = -999; b < 1000; ++b) {
			// Check prime streak.
			int streak = 0;
			for(int n = 0;;++n){
				int val = n * n + a * n + b;
				if(val < 0)
					break;
				if(val >= N){
					cerr << "!!NEED LARGER N\n";
					break;
				}
				if(prime[val]) ++streak;
				else break;
			}

			// // should be 40, 41.
			// if(a == 1 && b == 41)
			// 	cout << "*** " << streak << ' ' << a*b << '\n';

			if(streak > best_streak){
				best_a = a;
				best_b = b;
				best_streak = streak;
				// cout << best_a << ' ' << best_b << ' ' << best_streak << '\n';
			}

		}
	cout << best_a << ' ' << best_b << ' ' << best_streak << '\n';
	cout << best_a * best_b << '\n';
}
