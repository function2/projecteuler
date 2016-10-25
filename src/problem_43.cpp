// https://projecteuler.net/problem=43
// Michael Seyfert <michael@codesand.org>
/*
I'm sure there are ways to optimize this further, but for now brute
force will work.
 */
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

template<typename T>
T str_to(const string &s){
	istringstream iss(s);
	T t;
	iss >> t;
	return t;
}

class Problem43
{
public:
	typedef long long num_t;

	void Go(){
		// cerr << "got " << IsGoodPandigit("1406357289") << endl;

		string digits = "0123456789";
		int num_found = 0;
		num_t sum = 0;
		int cnt = 0;

		do{
			if(IsGoodPandigit(digits)){
				cerr << "Got: " << digits << endl;
				++num_found;
				sum += str_to<num_t>(digits);
			}

			if(++cnt % 400000 == 0)
				cerr << ((double)cnt / 3628800.0) * 100 << "%\n";
		}while(next_permutation(digits.begin(),digits.end()));

		cout << "Total found = " << num_found << '\n';
		cout << "Sum = " << sum << '\n';
	}

	bool IsGoodPandigit(const string &s)const
	{
		if(s.size() != 10)
			throw string("wtf");

		static const size_t N = 7;
		static const num_t DIVS[N] = {2,3,5,7,11,13,17};

		num_t subi[N];

		for(size_t k = 0;k < N; ++k)
			subi[k] = str_to<num_t>(s.substr(k+1,3));

		bool good = true;
		for(size_t k = 0;k < N;++k)
			if(subi[k] % DIVS[k] != 0){
				good = false;
				break;
			}
		return good;
	}
};

int main()
{
	Problem43 problem;
	problem.Go();
}
