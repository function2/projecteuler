// https://projecteuler.net/problem=32
// Michael Seyfert <michael@codesand.org>
#include<set>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>
using namespace std;

static set<int> products;
static int counter = 0;

template<class T>
int GetInt(const T &s)
{
	string str;
	for(typename T::const_iterator I = s.begin(); I != s.end();++I)
		str += *I;
	return atoi(str.c_str());
}

void TryEq(const set<char> &s1,const set<char> &s2, const set<char> &s3)
{
	// Can't solve no matter the digits. This is because one number is
	// too large.
	if(s1.size() + s2.size() - 2 > s3.size() - 1)
		return;
	if(s1.size() + s2.size() - 2 < s3.size() - 2)
		return;
	// There are no zeros in a solution.
	if(!s1.size() || !s2.size() || !s3.size())
		return;

	// Put in vectors and go through all permutations.
	vector<char> v1(s1.begin(),s1.end());
	vector<char> v2(s2.begin(),s2.end());
	vector<char> v3(s3.begin(),s3.end());
	do{
		do{
			do{
				int i1 = GetInt(v1);
				int i2 = GetInt(v2);
				int i3 = GetInt(v3);
				if(i1 * i2 == i3){
					products.insert(i3);
					//cout << i1 << " x " << i2 << " = " << i3 << '\n';
				}
			}while(next_permutation(v3.begin(),v3.end()));
		}while(next_permutation(v2.begin(),v2.end()));
	}while(next_permutation(v1.begin(),v1.end()));
}

void FindPandigital(set<char> remain,set<char> s1, set<char> s2,set<char> s3)
{
	if(remain.empty()){
		++counter;
		TryEq(s1,s2,s3);
		return;
	}

	// for(set<char>::const_iterator I = remain.begin(); I != remain.end(); ++I){
	set<char> newrem(remain);
	char c = *remain.begin();
	newrem.erase(c);
	{
		set<char> newset(s1);
		newset.insert(c);
		FindPandigital(newrem,newset,s2,s3);
	}
	{
		set<char> newset(s2);
		newset.insert(c);
		FindPandigital(newrem,s1,newset,s3);
	}
	{
		set<char> newset(s3);
		newset.insert(c);
		FindPandigital(newrem,s1,s2,newset);
	}
	// }
}

int main()
{
	const char r[] = "123456789";
	set<char> remain(&r[0],&r[sizeof(r)-1]);
	FindPandigital(remain,set<char>(),set<char>(),set<char>());
	if(counter != 3*3*3*3*3*3*3*3*3){
		cerr << "Counter incorrect value " << counter << endl;
		return EXIT_FAILURE;
	}
	int sum = 0;
	for(set<int>::const_iterator I = products.begin(); I != products.end(); ++I)
		sum += *I;
	cout << sum << '\n';
}
