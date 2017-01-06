// https://projecteuler.net/problem=38
// Michael Seyfert <michael@codesand.org>
#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<sstream>
using namespace std;

typedef long long num_t;

template<class T>
T ToInt(string s)
{
  istringstream iss(s);
  T t;
  iss >> t;
  return t;
}

bool IsPandigit(string s)
{
  bool d[10];
  memset(d,0,sizeof(d));
  for_each(s.begin(), s.end(),
           [&](char c){
             d[c-'0'] = true;
           });
  for(size_t k = 1;k < 10;++k)
    if(d[k] == false) return false;
  return true;
}

num_t TryNum(num_t k)
{
  // build the string.
  ostringstream oss;
  // k*1, k*2, ...
  for(num_t n = 1;oss.str().size() < 9;++n){
    oss << k*n;
  }
  string s = oss.str();
  if(s.size() != 9) return 0;
  return IsPandigit(s) ? ToInt<num_t>(s) : 0;
}

int main()
{
  num_t highest = 0;
  // Largest k is 4 digits.
  for(num_t k = 1; k < 10000;++k){
    num_t f = TryNum(k);
    if(f != 0)
      cerr << "Got " << k << " = " << f << endl;
    highest = max(f,highest);
  }
  cout << highest << '\n';
}
