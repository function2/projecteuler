// https://projecteuler.net/problem=20
// Michael Seyfert <michael@codesand.org>
/*
Problem Statement:

For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!
 */

/*
This can be solved in python3 in one line:

sum([int(d) for d in str(math.factorial(100))])

but we'll try not to cheat with bignums, hence this solution file.
 */
const int N = 100;

#include <iostream>
#include <vector>
using namespace std;

typedef int num;

int main()
{
	vector<num> digits(1,1);

	for(int k = 2;k <= N;++k){
		int x = k;

		// Multiples of 10 do not change the sum of the digits.
		while(x % 10 == 0)
			x /= 10;

		// Multiply times x.
		for(size_t j = 0;j < digits.size();++j)
			digits[j] *= x;

		// Take care of carryover.
		int carry_over = 0;
		for(size_t j = 0;j < digits.size();++j){
			digits[j] += carry_over;
			carry_over = digits[j] / 10;
			digits[j] %= 10;
		}
		while(carry_over){
			digits.push_back(carry_over % 10);
			carry_over /= 10;
		}
	}

	int s = 0;
	for(size_t k = 0;k < digits.size();++k){
		s += digits[k];
		// cout << digits[digits.size()-1 - k];
	}
	// cout << '\n';
	cout << s << '\n';
}
