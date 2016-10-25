// https://projecteuler.net/problem=42
// Michael Seyfert <michael@codesand.org>
/*
sum_{k=1}^n k = (1/2)n (n+1)
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Problem42
{
public:
	Problem42() : _count(0) {}

	void Input(const string &s){
		cerr << s;
		int value = 0;
		for(char c : s)
			value += (int)c - int('A') + 1;
		bool b = IsTriangleNum(value);
		_count += int(b);
		cerr << ' ' << b << endl;
	}

	int Count() const {return _count;}

private:
	// static const char *const ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int _count;
/*
return true if
 d = (1/2) n (n+1) for some integer n >=1
 */
	template<typename num>
	bool IsTriangleNum(num d)
	{
		num n = num();
		for(num k = 1;n < d;++k){
			n += k;
			if(n == d)
				return true;
		}
		return false;
	}
};

int main()
{
	Problem42 problem;
	ifstream ifs("data/p042_words.txt");
	string current_word;
	char c;

	while(ifs >> c){
		if(c == '"')
			continue;
		if(c == ','){
			problem.Input(current_word);
			current_word = string();
		}else
			current_word += c;
	}
	problem.Input(current_word);

	cout << problem.Count() << '\n';
}
