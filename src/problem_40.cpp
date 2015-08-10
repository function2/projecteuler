// https://projecteuler.net/problem=40
// Michael Seyfert <michael@codesand.org>
#include<iostream>
#include<sstream>
#include<vector>
using namespace std;

// do not instantiate std::vector<int> in this compilation unit.
// extern template class std::vector<int>;

template<typename T>
string ToString(const T &t)
{
  ostringstream oss;
  oss << t;
  return oss.str();
}

int main()
{
  vector<int> digits;
  digits.push_back(1);
  digits.push_back(10);
  digits.push_back(100);
  digits.push_back(1000);
  digits.push_back(10000);
  digits.push_back(100000);
  digits.push_back(1000000);

  size_t idx = 0;
  int prod = 1;
  int curr_num = 1;
  int curr_digit = 0;
  int next_digit = digits[0];
  bool done = false;
  for(;!done;++curr_num){
    string &&s = ToString(curr_num);
    for(char c : s){
      if(++curr_digit == next_digit){
        prod *= int(c - '0');
        idx += 1;
        if(idx == digits.size()){
          done = true;
          break;
        }
        next_digit = digits[idx];
      }
    }
  }
  cout << prod << endl;
}
