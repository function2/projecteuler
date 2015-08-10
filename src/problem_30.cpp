// https://projecteuler.net/problem=30
// Michael Seyfert <michael@codesand.org>
#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

const int FIFTH_TABLE[10] = {
	0 * 0 * 0 * 0 * 0,
	1 * 1 * 1 * 1 * 1,
	2 * 2 * 2 * 2 * 2,
	3 * 3 * 3 * 3 * 3,
	4 * 4 * 4 * 4 * 4,
	5 * 5 * 5 * 5 * 5,
	6 * 6 * 6 * 6 * 6,
	7 * 7 * 7 * 7 * 7,
	8 * 8 * 8 * 8 * 8,
	9 * 9 * 9 * 9 * 9
};

int SumDigits(int n){
	ostringstream oss;
	oss << n;
	string s = oss.str();
	int sum = 0;
	for(size_t k = 0;k < s.size();++k)
		sum += FIFTH_TABLE[(int)(s[k] - '0')];
	return sum;
}

int main()
{
	const int LIMIT_HIGH = 1000000;
	int sum = 0;
	for(int x = 2;x < LIMIT_HIGH;++x)
		if(x == SumDigits(x))
			sum += x;
	cout << sum << '\n';
}
