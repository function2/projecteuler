// https://projecteuler.net/problem=4
// Michael Seyfert <michael@codesand.org>
/*
Problem Statement:

A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.

 */

#include <sstream>
#include <iostream>
using namespace std;


bool IsPalindrome(int n)
{
	ostringstream ss;
	ss << n;
	string s = ss.str();

	for(size_t k = 0;k < s.size()/2;++k)
		if(s[k] != s[s.size()-1-k])
			return false;

	return true;
}

int main(int argc, char **argv)
{
	int largest = -1;
	for(int first = 999; first > 100; --first)
		for(int second = first-1; second >= 100; --second){
			int t = first*second;
			if(IsPalindrome(t)){
				// cout << format("Found palindrome: %1% x %2% = %3%.\n")
				// 	% first % second % t;
				if(t > largest)
					largest = t;
			}
		}

	cout << largest << '\n';
}
