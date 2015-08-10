// https://projecteuler.net/problem=18
// Michael Seyfert <michael@codesand.org>
/*
Problem Statement:

By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.

3
7 4
2 4 6
8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom of the triangle below:
...

NOTE: As there are only 16384 routes, it is possible to solve this problem by trying every route. However, Problem 67, is the same challenge with a triangle containing one-hundred rows; it cannot be solved by brute force, and requires a clever method! ;o)
*/

/*
That 'clever method' is simple dynamic (linear) programming.
Since there are no loops in the paths, we can keep track of the maxes for
every possible position from there on, thus we don't have to repeat subpaths.
 */
#include <vector>
#include <iostream>
using namespace std;

// const int TRI[] = {
// 	3,7,4,2,4,6,8,5,9,3
// };

const int TRI[] = {
	75,95,64,17,47,82,18,35,87,10,20,4,82,47,65,19,1,23,75,3,34,88,2,77,73,7,63,67,99,65,4,28,6,16,70,92,41,41,26,56,83,40,80,70,33,41,48,72,33,47,32,37,16,94,29,53,71,44,65,25,43,91,52,97,51,14,70,11,33,28,77,73,17,78,39,68,17,57,91,71,52,38,17,14,91,43,58,50,27,29,48,63,66,4,68,89,53,67,30,73,16,69,87,40,31,4,62,98,27,23,9,70,98,73,93,38,53,60,4,23
};

const int N = sizeof(TRI) / sizeof(TRI[0]);

int main()
{
	vector<int> maxes(N,-1);
	maxes[0] = TRI[0];
	int abs_max = -1; // highest value in maxes, this must be at the bottom;
	/*
	  left index of row n is n(n+1)/2,
	  right index of row n is (n+1)(n+2)/2 - 1
	  rows index starting at 0
	 */

	int prev_left_bound = 0;
	int prev_right_bound = 0;
	for(int row = 1;;++row){
		int left_row_bound = row*(row+1)/2;
		if(left_row_bound == N) break;
		int right_row_bound = (row+1)*(row+2)/2 - 1;

		int top_left = prev_left_bound - 1;
		int top_right = top_left + 1;
		for(int idx = left_row_bound; idx <= right_row_bound; ++idx){
			int left_sum = TRI[idx];
			int right_sum = TRI[idx];
			if(top_left >= prev_left_bound)
					left_sum += maxes[top_left];
			if(top_right <= prev_right_bound)
					right_sum += maxes[top_right];

			// cout << idx << ' ' << left_sum << ' ' << right_sum;
			maxes[idx] = max(left_sum,right_sum);
			// cout << " maxes[" << idx << "] = " << maxes[idx] << endl;
			abs_max = max(abs_max,maxes[idx]);

			++top_left, ++top_right;
		}

		// set new prev
		prev_left_bound = left_row_bound;
		prev_right_bound = right_row_bound;
	}

	cout << abs_max << '\n';
}
