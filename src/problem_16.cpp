// https://projecteuler.net/problem=16
// Michael Seyfert <michael@codesand.org>
/*
Problem Statement:

2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 2^1000?

*/
/*
This problem is easily solved with a bignum class, but that defeats the
purpose.
 */
#include <vector>
#include <iostream>
using namespace std;

int main()
{
	vector<int> digits(1);
	digits[0] = 1; // 2^0
	// Multiply by 2, 1000 times.
	for(int k = 0;k < 1000;++k){
		int carryover = 0;
		for(size_t j = 0;j < digits.size();++j){
			int r = digits[j] * 2 + carryover;
			digits[j] = r%10;
			carryover = r/10;
		}
		if(carryover)
			digits.push_back(carryover);
	}

	int r = 0;
	for(size_t j = 0;j < digits.size();++j)
		r += digits[j];
	cout << r << '\n';
}

/*
If there is no carry over in multiplying by 2, the sum of digits
doubles along with the number. This only happens if there are no digits
in the decimal number greater than 4. (for example 2^10 = 1024, 2^11 = 2048,
the sum of digits S(10) = 7, S(11) = 14.
*/
