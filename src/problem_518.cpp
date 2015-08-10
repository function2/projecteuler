// https://projecteuler.net/problem=518
// Michael Seyfert <michael@codesand.org>
// started: Sun May 31 06:16:58 UTC 2015
// Done 100315739184392
#include<iostream>
#include<vector>
#include<map>
#include<cmath>
using namespace std;

typedef long long count_t;

static const count_t NVAL = 1e8;

// Assumes a > b.
template<class T>
T gcd(const T &a, const T &b)
{
  if(b == 0) return a;
  return gcd(b, a % b);
}

int main()
{
  // Prime seive.
  vector<bool> is_prime(NVAL+1,true);
  for(int k = 2;k*k < NVAL;++k)
    if(is_prime[k])
      for(int j = 2*k;j < NVAL+1; j += k)
        is_prime[j] = false;
  is_prime[0] = is_prime[1] = false;

  // find (a, b, c)
  // where b = k/d * a, c = k^2/d^2 * a.
  count_t total = 0;
  for(count_t d = 1;d < NVAL;++d)
    for(count_t a = d*d;a < NVAL;a += d*d){
      if(is_prime[a-1]){
        count_t ad = a/d;
        count_t add = ad/d;

        for(count_t k = d+1; add*k*k <= NVAL; ++k){
          count_t b = ad * k;
          count_t c = add*k*k;
          if(is_prime[b-1] && is_prime[c-1] && gcd(k,d) == 1){
            // cout << " (" << a-1 << ' ' << b-1 << ' ' << c-1 << ") " << k << ' ' << d << endl;
            total += a + b + c - 3;
          }
        }
      }
    }

  printf("%lld\n",total);
}

// Brute force solution:
// typedef long long count_t;

// // static const int NVAL = 100;
// static const int NVAL = 1e8;

// // return a seive of all primes <= N.
// //  the vector will have N+1 components.
// vector<bool> PrimeSeive(int N)
// {
//   vector<bool> is_prime(N+1,true);

//   is_prime[0] = is_prime[1] = false;
//   // flag all evens.
//   for(int k = 4;k <= N; k += 2)
//     is_prime[k] = false;

//   for(int k = 3;k*k <= N; k += 2){
//     if(!is_prime[k]) continue;
//     // This value is prime, all multiples of it should be flagged.
//     for(int j = 2*k; j <= N; j += k)
//       is_prime[j] = false;
//   }

//   return is_prime;
// }

// int main()
// {
//   // First seive the primes.
//   vector<bool> &&is_prime = PrimeSeive(NVAL);

//   vector<int> primes;
//   for(size_t k = 0;k <= NVAL;++k)
//     if(is_prime[k])
//       primes.push_back(k);

//   cout << "Done computing primes, there are " <<
//     primes.size() << " primes <= " << NVAL << ".\n";

//   vector<count_t> sums(NVAL+1);
//   for(size_t ai = 0;ai < primes.size();++ai){
//     if(ai % 1000 == 0)
//       cout << ai << " / " << (primes.size()-1)
//            << " " << 100.00*((double)ai / (primes.size()-1)) << '%' << endl;
//     for(size_t bi = ai+1;bi < primes.size();++bi){
//       count_t a = primes[ai]+1;
//       count_t b = primes[bi]+1;
//       // c = b*b/a
//       if((b*b) % a == 0){
//         count_t c = b*b / a;
//         if(c > NVAL)
//           break;
//         sums[c] += (a + b + c) - 3;
//       }
//     }
//   }

//   count_t sum = 0;
//   for(size_t k = 2;k < NVAL;++k){
//     if(is_prime[k])
//       sum += sums[k+1];
//   }

//   cout << "Done " << sum << '\n';
// }
