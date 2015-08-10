// https://projecteuler.net/problem=37
// Michael Seyfert <michael@codesand.org>
#include<vector>
#include<iostream>
#include<sstream>
#include<string>
using namespace std;

void PrimeSieve(vector<bool> &is_prime, size_t N)
{
  is_prime.resize(N+1, true);
  is_prime[0] = is_prime[1] = false;

  // flag all even numbers.
  for(size_t k = 4;k <= N;k += 2)
    is_prime[k] = false;

  size_t j = 5,sq = 9; // sq = k*k throughout.
  for(size_t k = 3;sq <= N;++k){
    if(k % 2 != 0){
      // flag all factors false.
      for(size_t l = k*2;l <= N;l += k)
        is_prime[l] = false;
    }

    // update sq
    j += 2;
    sq += j;
  }
}

template<class T> string ToString(T t)
{
  ostringstream oss;
  oss << t;
  return oss.str();
}

template<class T> T StrToType(const string &s)
{
  istringstream iss(s);
  T t;
  iss >> t;
  return t;
}

inline bool IsTruncatablePrime(const vector<bool> &is_prime, size_t n)
{
  if(!is_prime[n])
    return false;

  string s = ToString(n);
  if(s.size() <= 1) return false;

  // left to right:
  for(string l = s.substr(1);l.size();l = l.substr(1)){
    if(!is_prime[StrToType<size_t>(l)])
      return false;
  }

  // right to left
  for(string r = s.substr(0,s.size()-1);
      r.size(); r = r.substr(0,r.size()-1)){
    if(!is_prime[StrToType<size_t>(r)])
      return false;
  }

  return true;
}

int main()
{
  static const int N = 11;
  static const int P = 10e6;

  int sum = 0;
  int num_got = 0;
  vector<bool> is_prime;
  PrimeSieve(is_prime, P);

  for(size_t k = 0;k < P;++k){
    if(IsTruncatablePrime(is_prime, k)){
      ++num_got;
      cout << "Got " << k << '\n';
      sum += k;
      if(num_got == N) break;
    }
  }

  cout << "Sum = " << sum << endl;
}
