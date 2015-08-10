// https://projecteuler.net/problem=17
// Michael Seyfert <michael@codesand.org>
/*
Problem Statement:

If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?

NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.

*/
#include <map>
#include <iostream>
using namespace std;

int main()
{
	map<int,string> words;
	words[1] = "one";
	words[2] = "two";
	words[3] = "three";
	words[4] = "four";
	words[5] = "five";
	words[6] = "six";
	words[7] = "seven";
	words[8] = "eight";
	words[9] = "nine";
	words[10] = "ten";
	words[11] = "eleven";
	words[12] = "twelve";
	words[13] = "thirteen";
	words[14] = "fourteen";
	words[15] = "fifteen";
	words[16] = "sixteen";
	words[17] = "seventeen";
	words[18] = "eighteen";
	words[19] = "nineteen";

	words[20] = "twenty";
	words[30] = "thirty";
	words[40] = "forty";
	words[50] = "fifty";
	words[60] = "sixty";
	words[70] = "seventy";
	words[80] = "eighty";
	words[90] = "ninety";

	string hundred = "hundred";
	string thousand = "thousand";

	int sum = 0;

	for(int k = 1;k < 1000;++k) {
		cout << k << ' ';
		int j = k % 100;
		if(j){
			if(words[j] != ""){
				cout << words[j];
				sum += words[j].size();
			}else{
				cout << words[j / 10 * 10] + words[j%10];
				sum += words[j / 10 * 10].size() + words[j%10].size();
			}
		}
		j = k / 100;
		if(j){
			cout << words[j] << hundred;
			sum += words[j].size() + hundred.size();
			if(k%100 != 0){
				cout << "and";
				sum += 3;
			}
		}
		cout << '\n';
	}
	cout << 1000 << ' ' << words[1] << thousand << '\n';
	sum += words[1].size() + thousand.size();
	cout << sum << '\n';
}
