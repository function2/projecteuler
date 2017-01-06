// https://projecteuler.net/problem=34
// Michael Seyfert <michael@codesand.org>
/*
145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

Find the sum of all numbers which are equal to the sum of the
factorial of their digits.

Note: as 1! = 1 and 2! = 2 are not sums they are not included.
*/

/*
smallest n digit is
100000...0000
largest is all 999999...999
The largest sum is then (9!)*n
smallest n for which we have 10^n-1 > (9!)*n

considering
(9!) = 362880 (6 digits)
(9!) 7 = 2540160
for 7 digits, the highest factorial sum you can get is 2540160.
Any digits higher and it will never be equal (as the power increases
faster than the multiply.

We only have to go up to (9!) 7.
*/

#include <cstdlib>

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

long long FAC[] = {
  1, // 0!
  1,
  2,
  3*2,
  4*3*2,
  5*4*3*2,
  6*5*4*3*2,
  7*6*5*4*3*2,
  8*7*6*5*4*3*2,
  9*8*7*6*5*4*3*2
};

bool TestString(const string &s)
{
  long long sum = 0;
  for_each
    (s.begin(), s.end(),
     [&](char c){
      sum += FAC[c - '0'];
    });

  // test the result
  ostringstream oss;
  oss << sum;
  return oss.str() == s;
}

int main()
{
  long long sum = 0;
  for(int k = 3; k <= 2540160; ++k){
    ostringstream oss;
    oss << k;
    if(TestString(oss.str())) {
      cout << "Got " << k << endl;
      sum += k;
    }
    if(k % 100000 == 0) cout << k << endl;
  }
  cout << "Sum = " << sum << endl;
  return EXIT_SUCCESS;
}
