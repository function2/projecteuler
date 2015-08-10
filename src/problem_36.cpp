// https://projecteuler.net/problem=36
// Michael Seyfert <michael@codesand.org>
/*
The decimal number, 585 = (1001001001)_2 (binary), is palindromic in
both bases.

Find the sum of all numbers, less than one million, which are
palindromic in base 10 and base 2.

(Please note that the palindromic number, in either base, may not
include leading zeros.)
*/

#include <iostream>
#include <sstream>
#include <string>
#include <bitset>
using namespace std;

template<class T>
string ToString(T n)
{
  ostringstream oss;
  oss << n;
  return oss.str();
}

template<class T>
string ToString2(T n)
{
  bitset<32> b(n);
  ostringstream oss;
  oss << b;
  return oss.str();
}

bool IsPalindrome10(int n)
{
  string s = ToString(n);
  const size_t L = s.size();
  for(size_t k = 0;k < L/2;++k) // assume L/2 = floor(L/2)
    if(s[k] != s[L-k-1])
      return false;
  return true;
}

bool IsPalindrome2(int n)
{
  string s = ToString2(n);
  size_t k = 0;
  while(s[k] == '0') ++k; // skip leading zeros
  size_t L = s.size() - k;
  for(size_t j = 0;j < L/2;++j) // assume L/2 = floor(L/2)
    if(s[j+k] != s[s.size()-j-1])
      return false;
  return true;
}

int main()
{
  int sum = 0;
  for(int k = 1;k < 1e6;++k)
    if(IsPalindrome10(k) && IsPalindrome2(k)){
      sum += k;
      // cout << "Got " << k << ' ' << ToString2(k) << '\n';
    }
  cout << sum << endl;
}
