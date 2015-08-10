// https://projecteuler.net/problem=29
// Michael Seyfert <michael@codesand.org>
#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;

typedef map<int,int> pfac_t;

void GetPrimeFactors(pfac_t &p, size_t n)
{
	while(n % 2 == 0){
		n /= 2;
		++p[2];
	}
	for(size_t k = 3;k <= n;k += 2){
		while(n % k == 0){
			n /= k;
			++p[k];
		}
	}
}

// void Print(const pfac_t *p)
// {
// 	cout << "Primes:";
// 	for(pfac_t::const_iterator I = p->begin(); I != p->end();++I)
// 		cout << ' ' << I->first << ':' << I->second;
// 	cout << '\n';
// }

pfac_t FactorPower(pfac_t p,size_t power)
{
	pfac_t tmp;
	for(pfac_t::const_iterator I = p.begin();I != p.end();++I)
		tmp[I->first] = I->second * power;
	return tmp;
}

int main()
{
	const size_t N = 100;
	vector<pfac_t> a(N+1);
	for(size_t k = 2;k <= N;++k)
		GetPrimeFactors(a[k],k);
	set<pfac_t> sorter;
	for(size_t b = 2;b <= N;++b) // powers from [2,N]
		for(size_t k = 2;k <= N;++k)
			sorter.insert(FactorPower(a[k],b));
	cout << sorter.size() << endl;
}
