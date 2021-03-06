// https://projecteuler.net/problem=2
// Michael Seyfert <michael@codesand.org>
/*
Problem Statement:

Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:

1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.

 */

#include<iostream>
using namespace std;

static const size_t MAX_VAL = 4e6;

int main(int argc, char **argv)
{
	size_t sum = 0;
	size_t x0 = 1, x1 = 2;
	do{
		sum += !(x1 % 2) ? x1 : 0;
		size_t t = x1;
		x1 += x0;
		x0 = t;
	}while(x1 <= MAX_VAL);
	cout << sum << '\n';
}
