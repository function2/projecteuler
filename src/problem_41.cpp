// https://projecteuler.net/problem=41
// Michael Seyfert <michael@codesand.org>

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool IsPrime(const int &num)
{
  if(num <= 3) return true;
  if(num % 2 == 0)
    return false;
  for(int k = 3;k*k <= num;k+=2)
    if(num % k == 0)
      return false;
  return true;
}

int LargestPandigit(int num_digits)
{
  //  cout << "Trying all permutations of " << num_digits << " digits.\n";
  vector<int> digits(num_digits);
  for(int k = 0;k < num_digits;++k)
    digits[k] = k+1;

  int highest = 0;
  do{
    int test_num = 0;
    for(int k = 0; k < num_digits; ++k){
      test_num *= 10;
      test_num += digits[k];
    }

    if(IsPrime(test_num)){
      highest = test_num;
    }
  }while(next_permutation(digits.begin(),digits.end()));

  return highest;
}

int main()
{
  int highest = 0;
  for(int k = 1;k <= 9;++k)
    highest = max(LargestPandigit(k), highest);
  cout << highest << endl;
}
