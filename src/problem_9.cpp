// https://projecteuler.net/problem=9
// Michael Seyfert <michael@codesand.org>
/*
Problem Statement:

A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
a2 + b2 = c2

For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.

*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	const long double EPS = 1e-9;

	for(size_t a = 2; a < 1000;++a){
		for(size_t b = a; b < 1000;++b){
			size_t c2 = a*a + b*b;
			long double n1 = a;
			long double n2 = b;
			long double n3 = c2;
			n3 = sqrt(n3);
			long double nf = floorl(n3); // TODO floats always causing problems.
			long double nc = ceill(n3);
			if(nf >= nc-EPS && nf <= nc+EPS){
				long double sum = n1 + n2 + n3;
				if(sum >= 1000-EPS && sum <= 1000+EPS){
					// cout << " a = " << a;
					// cout << " b = " << b;
					// cout << " c = " << n3;
					// cout << " abc = " << int(a*b*n3);
					cout << int(a*b*n3) << '\n';
					break;
				}
			}
		}
	}
}
