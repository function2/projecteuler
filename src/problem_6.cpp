// https://projecteuler.net/problem=6
// Michael Seyfert <michael@codesand.org>
/*
Problem Statement:

The sum of the squares of the first ten natural numbers is,
1^2 + 2^2 + ... + 10^2 = 385

The square of the sum of the first ten natural numbers is,
(1 + 2 + ... + 10)^2 = 55^2 = 3025

Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

 */

/*
The square of the sum is:
\left[ \frac{n(n+1)}{2} \right]^2

The sum of squares is:
1/3 n^3 + 1/2 n^2 + 1/6 n
(You can prove this by assuming the answer is a cubic polynomial and solving
for the coefficients.)

The answer in closed form is then:
n^4/4 + n^3/6 - n^2 / 4 - n/6

in python3:
n**4 / 4 + n**3 / 6 - n**2/4 - n/6
which gives
25164150
 */
#include<vector>
#include<map>
#include<iostream>
using namespace std;

int main()
{
	static const int N = 100;
	int n2 = N*N;
	int n3 = n2*N;
	int n4 = n3*N;
	cout << int(n4/4.0 + n3/6.0 - n2/4.0 - N/6.0) << '\n';
}
