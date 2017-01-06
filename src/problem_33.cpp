// https://projecteuler.net/problem=33
// Michael Seyfert <michael@codesand.org>
#include<iostream>
#include<vector>
#include<map>
#include<sstream>
using namespace std;

template<class T>
map<T,int> GetPrimeFactors(T num)
{
	map<T,int> r;
	if(num == T(0)) return r;

	while(num % T(2) == 0){
		num /= T(2);
		++r[T(2)];
	}
	for(T k(3);k*k <= num;k+=T(2)){
		while(num % k == 0){
			num /= k;
			++r[T(k)];
		}
	}
	// Whatever remains is prime.
	if(num != T(1))
		++r[T(num)];
	return r;
}

template<class T>
int ToInt(const map<T,int> &num)
{
	int r = 1;
	for(auto I = num.begin();I != num.end();++I)
		for(int k = 0;k < I->second;++k)
			r *= I->first;
	return r;
}

template<class T>
void RemoveUnion(map<T,int> &a, map<T,int> &b)
{
	for(auto I = a.begin();I != a.end();++I){
		auto J = b.find(I->first);
		if(J != b.end()){
			int minval = min(I->second, J->second);
			I->second -= minval;
			J->second -= minval;
		}
	}
}

template<class T>
string ToStr(T n)
{
	ostringstream oss;
	oss << n;
	return oss.str();
}

bool Check(int test_n, int test_d,int ni, int di)
{
	if(!test_n || !test_d)
		return false;
	map<int,int> nt = GetPrimeFactors<int>(test_n);
	map<int,int> dt = GetPrimeFactors<int>(test_d);
	RemoveUnion(nt,dt);
	return ni == ToInt(nt) && di == ToInt(dt);
}

pair<int,int> CheckNum(int num, int den)
{
	map<int,int> np,num_fac = GetPrimeFactors<int>(num);
	map<int,int> dp,den_fac = GetPrimeFactors<int>(den);
	np = num_fac;
	dp = den_fac;

	// Cancel numerator and denominator factors in common.
	RemoveUnion(np,dp);
	int ni = ToInt(np);
	int di = ToInt(dp);

	// Look at the digits, see if there is any in common.
	string n = ToStr(num);
	string d = ToStr(den);
	if(n.size() > 1 && d.size() > 1){
		// First and last digits cancelling are considered trivial and
		//  are not counted.
		// First digits.
		// if(n[0] == d[0]){
		// 	int test_n = atoi(&n[1]);
		// 	int test_d = atoi(&d[1]);
		// 	if(Check(test_n,test_d,ni,di));
		// }
		// Cross 1.
		if(n[0] == d[1]){
			int test_n = atoi(&n[1]);
			int test_d = atoi(d.substr(0,1).c_str());
			if(Check(test_n,test_d,ni,di)){
				printf("%d/%d = %d/%d\n",num,den,test_n,test_d);
				return make_pair(test_n,test_d);
			}
		}
		// Cross 2.
		if(n[1] == d[0]){
			int test_n = atoi(n.substr(0,1).c_str());
			int test_d = atoi(&d[1]);
			if(Check(test_n,test_d,ni,di)){
				printf("%d/%d = %d/%d\n",num,den,test_n,test_d);
				return make_pair(test_n,test_d);
			}
		}
		// Last digits.
		// if(n[1] == d[1]){
		// 	int test_n = atoi(n.substr(0,1).c_str());
		// 	int test_d = atoi(d.substr(0,1).c_str());
		// 	if(Check(test_n,test_d,ni,di));
		// }
	}
	return pair<int,int>();
}

int main()
{
	map<int,int> num,den;
	for(int k = 1;k < 100;++k)
		for(int j = k+1;j < 100;++j){
			pair<int,int> t = CheckNum(k,j);
			if(t.first){
				map<int,int> n = GetPrimeFactors(t.first);
				map<int,int> d = GetPrimeFactors(t.second);
				for(map<int,int>::const_iterator I = n.begin();I != n.end();++I)
					num[I->first] += I->second;
				for(map<int,int>::const_iterator I = d.begin();I != d.end();++I)
					den[I->first] += I->second;
			}
		}
	RemoveUnion(num,den);
	cout << ToInt(den) << '\n';
}
