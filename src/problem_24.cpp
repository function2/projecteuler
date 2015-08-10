// https://projecteuler.net/problem=24
// Michael Seyfert <michael@codesand.org>
/*
Problem Statement:

A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:

012   021   102   120   201   210

What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?

*/

/*
using c++ next_permutation makes this simple.
 */
#include<algorithm>
#include<iostream>
using namespace std;

// Implement my own next_permutation for educational purposes.
// if the new permutation is sorted, return false.
template<typename T>
bool my_next_permutation(T *first, T *last)
{
	// Go backwards looking for smaller values.
	T *curr = last-1;
	T *prev = last-1;
	while(curr != first){
		prev = curr-1;
		if(*prev < *curr) break;
		--curr;
	}

	if(prev == curr) prev = NULL;
	T *curr_save = curr;

	// Reverse everything from last-1 to curr,
	for(T *back = last-1;back > curr;--back,++curr)
		std::swap(*back,*curr);

	// Find the next largest to prev.
	// Could do a binary search to speed this up, or put code for next_largest
	// in the previous loop somehow.
	// TODO there is certainly a faster way to do this.
	// but really how big are permutations going to be? they grow factorially.
	T *next_largest = last-1;
	if(prev)
		for(T *curr = curr_save;curr < last;++curr)
			if(*curr > *prev && *curr < *next_largest){
				next_largest = curr;
				break; // since it is sorted from here on, we're done.
			}

	if(prev){
		std::swap(*next_largest, *prev);
		return true;
	}
	return false;
}

/*
 Solution with STL next_permutation(),
This solution works just fine and gives the correct answer,
 2783915460.
*/
int main()
{
	// There are 10! = 3,628,800 possible permutations.

	// Start with the lexicographically first permutation.
	char digits[10] = {0,1,2,3,4,5,6,7,8,9};
	const int N = sizeof(digits) / sizeof(digits[0]);

	//============================================================
	// // This code gives a sorted list of all possible permutations.
	// // STL and my own implementation of next_permutation should give the same
	// // results.
	// do{
	// 	for(int k = 0;k < N;++k)
	// 		cout << (char)(digits[k] + '0');
	// 	cout << '\n';
	// }while(my_next_permutation(digits, digits+N)); // Using my own.
	// //}while(next_permutation(digits, digits+N)); // Using STL.
	// // Should be sorted afterwards.
	// for(int k = 0;k < N;++k)
	// 	cout << (char)(digits[k] + '0');
	// cout << '\n';
	//============================================================

	for(int curr = 1; curr < 1e6; ++curr)
		my_next_permutation(digits, digits+N);

	for(int k = 0;k < N;++k)
		cout << (char)(digits[k] + '0');
	cout << '\n';

}
