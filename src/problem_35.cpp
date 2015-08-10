// https://projecteuler.net/problem=35
// Michael Seyfert <michael@codesand.org>
/*
The number, 197, is called a circular prime because all rotations of
the digits: 197, 971, and 719, are themselves prime.  There are
thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71,
73, 79, and 97.  How many circular primes are there below one million?
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

void MakePrimeSieve(vector<bool> &is_prime, size_t n)
{
  is_prime.resize(n+1,true);
  is_prime[0] = is_prime[1] = false;

  for(size_t k = 2; k * k <= n; ++k) {
    if(is_prime[k] == false)
      continue;
    size_t j = k;
    while((j+=k) <= n)
      is_prime[j] = false;
  }
}

template<class T>
string ToString(const T &t)
{
  ostringstream oss;
  oss << t;
  return oss.str();
}

size_t ToNum(const string &t)
{
  size_t s;
  istringstream iss(t);
  iss >> s;
  return s;
}

int main()
{
  int answer = 0;

  // sieve all primes below 10 million.
  vector<bool> is_prime;
  MakePrimeSieve(is_prime, 10e6);

  for(size_t k = 2; k < 1e6;++k) {
    if(!is_prime[k]) continue;
    bool good = true;
    // Check all rotations
    string s = ToString(k);
    for(size_t j = 0;j < s.size();++j){
      if(!is_prime[ToNum(s)]){
        good = false;
        break;
      }
      rotate(s.begin(),s.begin()+1,s.end());
    }
    if(good){
      cout << "Got " << k << '\n';
      ++answer;
    }
  }

  cout << "Answer = " << answer << endl;
}
