// https://projecteuler.net/problem=26
// Michael Seyfert <michael@codesand.org>
/*
Problem Statement:

A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:

    1/2	= 0.5
    1/3	= 0.(3)
    1/4	= 0.25
    1/5	= 0.2
    1/6	= 0.1(6)
    1/7	= 0.(142857)
    1/8	= 0.125
    1/9	= 0.(1)
    1/10= 0.1

Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.

Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.
*/

/*
Interesting fact: to get repeating decimals in base 10 do:
(d_1 d_2 d_3 d_4) / 9999 (gives 4 repeating digits).
for example 1234/9999 = .(1234)
This is easy to prove (geometric sum).
 */
#include<map>
#include<string>
#include<iostream>
#include<sstream>
using namespace std;

// template<typename T>
// string to_str(const T &t)
// {
// 	ostringstream oss;
// 	oss << t;
// 	return oss.str();
// }

// This finds the non-repeating and repeating parts of the fraction.
int Find(int d)
{
	int num = 1;
	int p = 0; // power.

	map<int,int> used; // [numerator] = power
	pair<map<int,int>::iterator,bool> I;
	used[0] = -1;
	for(;;){
		I = used.insert(make_pair(num,p));
		if(I.second == false)
			break;
		while(num < d){ num *= 10; ++p;}
		num = num % d; // Our new num to divide is the remainder.
	}

	// If the remainder was zero then it evenly divided and we're done,
	// no recurring digits
	if(num == 0)
		return 0;

	return p - I.first->second;
}

int main()
{
	int r = -1;
	int best = 0;
	for(int d = 1;d < 1000;++d){
		int n = Find(d);
		if(n >= r){
			best = d;
			r = n;
		}
	}
	cout << best << '\n';
}
