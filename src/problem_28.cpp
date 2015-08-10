// https://projecteuler.net/problem=28
// Michael Seyfert <michael@codesand.org>
/*
Problem Statement:

Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:

21 22 23 24 25
20  7  8  9 10
19  6  1  2 11
18  5  4  3 12
17 16 15 14 13

It can be verified that the sum of the numbers on the diagonals is 101.

What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?

Mon Nov 17 01:02:37 UTC 2014
*/

#include<iostream>
using namespace std;

int main()
{

	int n = 1;
	int counter = 1;
	int sum = 1;
	do{
		n += 2; // increase matrix size by 2
		counter += (n-1); // low right
		sum += counter;
		counter += (n-1); // low left
		sum += counter;
		counter += (n-1); // up left
		sum += counter;
		counter += (n-1); // up right
		sum += counter;
	}while(n < 1001);
	cout << sum << '\n';
}
