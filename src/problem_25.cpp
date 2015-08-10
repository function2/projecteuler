// https://projecteuler.net/problem=25
// Michael Seyfert <michael@codesand.org>
/*
Problem Statement:

The 12th term, F12, is the first term to contain three digits.

What is the first term in the Fibonacci sequence to contain 1000 digits?
*/

/*
We cheat using a bignum.
It would be easy enough to implement addition, but I'd rather not.
 */
#include<iostream>
#include<sstream>
#include<gmpxx.h>
using namespace std;

typedef mpz_class num;
const num N = 1000;

int main()
{
	num f1 = 1;
	num f2 = 1;

	for(num k = 3;;++k){
		num t = f1 + f2;
		f2 = f1;
		f1 = t;

		// here f1 contains the kth Fibonacci term
		string s;
		ostringstream oss;
		oss << f1;
		s = oss.str();
		if(s.size() == N){
			cout << k << '\n';
			break;
		}
	}
}
