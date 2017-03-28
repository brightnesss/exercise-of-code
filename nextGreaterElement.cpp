#include "includelib.h"

// leetcode No.496 Next Greater Element I 

/*
 *	You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2. 
 *	Find all the next greater numbers for nums1's elements in the corresponding places of nums2. 
 *	The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2.
 *	If it does not exist, output -1 for this number. 
 */

// 遍历每一个数，将它压栈，若之后遍历到的数比栈顶的数大，则栈顶的数找到了nextGreaterElement
// 将其退栈

vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums)
{
	stack<int> bin;
	unordered_map<int, int> intMap;
	for (int i : nums)
	{
		while (!bin.empty() && i > bin.top())
		{
			intMap[bin.top()] = i;
			bin.pop();
		}
		bin.push(i);
	}

	vector<int> ans;
	for (int i : findNums)
	{
		ans.push_back(intMap.count(i) ? intMap[i] : -1);
	}
	return ans;
}