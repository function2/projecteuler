// https://projecteuler.net/problem=31
// Michael Seyfert <michael@codesand.org>
#include<iostream>
#include<cstring>
#include<gmpxx.h>
using namespace std;

int memo[200][8];

int Count(int sum,int largest_type){
	if(sum > 200) return 0;
	if(sum == 200) return 1;

	int &m = memo[sum][largest_type];
	if(m != -1) return m;

	// Try all currencies.
	int count = 0;
	if(largest_type <= 0)
		count += Count(sum + 1,0); // 1 pence
	if(largest_type <= 1)
		count += Count(sum + 2,1); // 2 pence
	if(largest_type <= 2)
		count += Count(sum + 5,2);
	if(largest_type <= 3)
		count += Count(sum + 10,3);
	if(largest_type <= 4)
		count += Count(sum + 20,4);
	if(largest_type <= 5)
		count += Count(sum + 50,5);
	if(largest_type <= 6)
		count += Count(sum + 100,6);
	if(largest_type <= 7)
		count += Count(sum + 200,7);

	return m = count;
}

int main()
{
	memset(memo,-1,sizeof(memo));
	// Prevent stack overflow by starting at 1 remaining.
	for(int k = 199;k;--k)
		Count(k,0);
	cout << Count(0,0) << '\n';
	// for(int k = 0;k < 200;++k)
	// 	cout << Count(k,0) << '\n';
}
