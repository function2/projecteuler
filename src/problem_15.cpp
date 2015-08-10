// https://projecteuler.net/problem=15
// Michael Seyfert <michael@codesand.org>
/*
Problem Statement:

Starting in the top left corner of a 2×2 grid, and only being able to
move to the right and down, there are exactly 6 routes to the bottom
right corner.

How many such routes are there through a 20×20 grid?
*/

#include<iostream>
#include<cstring>
using namespace std;

// We need 64 bit for this to work.
typedef long numtype;

const numtype N = 20;

static numtype memo[N+1][N+1];
numtype NumRoutes(numtype x,numtype y)
{
	if(x > N || y > N) return 0;

	numtype &m = memo[x][y];
	if(m != -1) return m;

	if(x == N && y == N) return m = 1;

	numtype moves = 0;
	moves += NumRoutes(x+1,y);
	moves += NumRoutes(x,y+1);
	return m = moves;
}

#include <iostream>
using namespace std;

int main()
{
	memset(memo,-1,sizeof(memo));
	cout << NumRoutes(0,0) << '\n';
}
