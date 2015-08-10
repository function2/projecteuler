// https://projecteuler.net/problem=39
// Michael Seyfert <michael@codesand.org>
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

static double EPS = 1e-10; // We don't need much precision.
static const int D = 1000;

int main()
{
  vector<int> counts(D+1,0);

  for(int a = 1; a <= D; ++a)
    for(int b = a; b <= D; ++b){
      int c2 = a*a + b*b;
      double sc = sqrt(c2);
      double e = sc - round(sc);
      if(abs(e) > EPS)
        continue; // non-integral
      int c = (int)round(sc);
      // Get the perimiter.
      int p = a + b + c;
      if(p <= D)
        ++counts[p];
    }

  int high = 0;
  int high_idx = -1;
  for(int k = 0;k <= D;++k){
    if(counts[k] > high){
      high = counts[k];
      high_idx = k;
    }
  }
  cout << "Soln: " << high_idx << endl;
}
