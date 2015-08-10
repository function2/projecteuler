// https://projecteuler.net/problem=521
// Michael Seyfert <michael@codesand.org>
// started: Thu Jun 25 07:00:09 UTC 2015
/*
Let smpf(n) be the smallest prime factor of n.
smpf(91)=7 because 91=7×13 and smpf(45)=3 because 45=3×3×5.
Let S(n) be the sum of smpf(i) for 2 ≤ i ≤ n.
E.g. S(100)=1257.

Find S(10^12) mod 10^9.
*/
// This is a brute force solution.
// 44389811
#include<vector>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;

typedef long long count_t;

// const count_t M = 1e9;
// const count_t N = 100;
// // Seive this many at a time.
// const count_t BLOCK_SIZE = 7;

const count_t M = 1e9;
const count_t N = 1e12;
// Seive this many at a time.
const count_t BLOCK_SIZE = 20e6;

int main()
{
  const count_t S = sqrtl((long double)N);

  // Prime seive up to sqrt(N)
  vector<bool> is_prime(S+1,true);
  is_prime[0] = is_prime[1] = false;
  for(int k = 2;k <= S;++k)
    if(is_prime[k]){
      for(int j = k+k;j <= S;j += k)
        is_prime[j] = false;
    }

  vector<count_t> primes;
  for(size_t k = 0;k < is_prime.size();++k)
    if(is_prime[k])
      primes.push_back(k);

  count_t sum = 0;

  // main loop.
  for(count_t k = 0;k < N;k += BLOCK_SIZE){
    cout << " k = " << k << ' ' << 100.0 * double(k) / N << endl;
    vector<count_t> s(BLOCK_SIZE, 0);

    // mark lowest primes.
    for(count_t j = 0;j < primes.size();++j){
      count_t low;
      if(k % primes[j] == 0)
        low = 0;
      else
        low = primes[j] - k % primes[j];
      for(count_t i = low; i < BLOCK_SIZE; i += primes[j])
        if(s[i] == 0){
          s[i] = primes[j];
          // cout << "set lowest " << k+i << " = " << primes[j] << endl;
        }
    }
    // sum
    for(count_t j = 0;j < min((count_t)s.size(), N - k);++j){
      if(s[j] == 0){
        sum += ((k % M) + (j % M)) % M; // is prime.
        sum %= M;
      }else{
        sum += (s[j]) % M;
        sum %= M;
      }
    }
  }

  // Assume last num has smallest factor 2.
  cout << (sum-1) << endl;
  cout << (sum-1) % M << endl;

  // // Prime seive up to sqrt(N)
  // vector<bool> is_prime(S+1,true);
  // is_prime[0] = is_prime[1] = false;
  // for(int k = 2;k <= S;++k)
  //   if(is_prime[k]){
  //     for(int j = k+k;j <= S;j += k)
  //       is_prime[j] = false;
  //   }

  // vector<int> primes;
  // for(size_t k = 0;k < is_prime.size();++k)
  //   if(is_prime[k])
  //     primes.push_back(k);

  // // main loop
  // count_t total = 0;
  // for(count_t k = 2;k <= N;++k) {
  //   if(k % 100000 == 0)
  //     cout << k << ' ' << 100.0 * double(k) / N << endl;
  //   if(k <= S && is_prime[k]){
  //     // cout << k << endl;
  //     total += k; //(k % M);
  //     continue;
  //   }
  //   // Check smallest prime factor.
  //   count_t use = 0;
  //   for(size_t j = 0;j < primes.size();++j)
  //     if(k % primes[j] == 0){
  //       use = primes[j];
  //       break;
  //     }
  //   total += (use ? use : k) % M;
  //   // if(use){
  //   //   cout << k << ' ' << use << endl;
  //   // }else
  //   //   cout << k << endl; // is prime.
  // }

  // cout << total << endl;
}
