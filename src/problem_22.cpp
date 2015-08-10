// https://projecteuler.net/problem=22
// Michael Seyfert <michael@codesand.org>
/*
Problem Statement:

Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.

What is the total of all the name scores in the file?

 */
/*
First we modify the input file to something we can read easily.
sed 'y/,"/\n /' problem_22_names.txt > problem_22_names_edit.txt
TODO: parse this within my program.
 */
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <set>
using namespace std;

int main()
{
	// Read the input file.
	const char*const FILENAME = "data/problem_22_names_edit.txt";
	ifstream is(FILENAME);
	if(!is){
		cerr << "Unable to open input file: " << FILENAME << '\n';
		return EXIT_FAILURE;
	}
	// Sort it while reading.
	set<string> names;
	string s;
	for(is >> s; is ; is >> s){
		names.insert(s);
	}
	if(is.bad()){
		cerr << "Error while reading the stream: " << FILENAME << '\n';
		return EXIT_FAILURE;
	}

	// Calculate the score for each name.
	int pos = 1;
	int total_score = 0;
	for(set<string>::const_iterator I = names.begin();I != names.end();++I,++pos){
		int score = 0;
		const string &name = *I;
		for(string::const_iterator J = name.begin();J != name.end();++J)
			score += (*J - 'A' + 1) * pos;
		total_score += score;
	}
	cout << total_score << '\n';
}
