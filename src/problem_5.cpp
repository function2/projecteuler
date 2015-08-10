// https://projecteuler.net/problem=5
// Michael Seyfert <michael@codesand.org>
/*
Problem Statement:

2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

 */
#include<vector>
#include<map>
#include<iostream>
using namespace std;

// Recursive GCD
template<typename T>
T GCD(const T &a, const T &b)
{
	if(b == T()) return a;
	return GCD(b, a % b);
}

template<typename T>
T LCM(const T &a, const T &b)
{
	return a * b / GCD(a,b);
}

// Recursive LCM
template<typename T>
T LCM2(const T &a, const T &b)
{
	T c = a%b;
	if(c == T()) return a;
	return a * LCM2(b,c) / c;
}

int main()
{
	size_t ans = 1;
	for(size_t k = 2;k <= 20; ++k)
		ans = LCM(ans,k);
	cout << ans << '\n';
}

//===== A more complex solution:

// bool IsPrime(size_t n)
// {
// 	if(n <= 1) return false;
// 	if(n == 2) return true;
// 	if(!(n % 2)) return false;
// 	for(size_t k = 3;k*k <= n;k+=2)
// 		if(!(n % k)) return false;
// 	return true;
// }

// void GetPrimeFactors(std::vector<size_t> &pfactors,size_t n)
// {
// 	pfactors.clear();

// 	for(size_t k = 2;n > 1;++k)
// 		if(IsPrime(k)){
// 			while(!(n % k)){
// 				n /= k;
// 				pfactors.push_back(k);
// 			};
// 		}
// }

// int main(int argc, char **argv)
// {
// 	// This problem is asking for the lowest common multiple of [2,20],
// 	// which is the product of the largest power of all prime factors from
// 	// numbers 2 to 20.

// 	map<size_t,size_t> facs; // [prime #] = power.

// 	for(size_t k = 2;k <= 20; ++k){
// 		vector<size_t> pfactors;
// 		GetPrimeFactors(pfactors,k);
// 		map<size_t,size_t> tmp;
// 		for(size_t j = 0;j < pfactors.size();++j)
// 			tmp[pfactors[j]]++;
// 		for(auto I = tmp.cbegin(); I != tmp.cend();++I)
// 			if(facs[I->first] < I->second)
// 				facs[I->first] = I->second;
// 	}

// 	size_t soln = 1;
// 	for(auto I = facs.cbegin(); I != facs.cend();++I)
// 		for(size_t k = 0;k < I->second;++k)
// 			soln *= I->first;

// 	cout << soln << '\n';

// }
