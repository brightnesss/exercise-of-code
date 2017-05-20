// leetcode No.453 Minimum Moves to Equal Array Elements 

/*
 *	Given a non-empty integer array of size n, find the minimum number of moves required to make all array elements equal
 *	where a move is incrementing n - 1 elements by 1.
 */

#include "inlcudelib.h"

int minMoves(vector<int>& nums)
{
	int sum = accumulate(nums.begin(), nums.end(), 0);
	vector<int>::iterator minIter = min_element(nums.begin(), nums.end());
	int ans = sum - *minIter*nums.size();
	return ans;
}

/*
 *	This is a math problem
 *	Assume m is the answer of this problem, n is the size of vector nums
 *	then
 *	sum + m * (n - 1) = n * x
 *	where x = minNum + m
 *	minNum is the min of initial vector nums
 *	To solve this equation, we can get m = sum - n * minNum
 */