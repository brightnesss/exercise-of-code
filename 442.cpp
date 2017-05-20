//leetcode No.442 Find All Duplicates in an Array 

/*
 *	Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
 *	Find all the elements that appear twice in this array.
 *	Could you do it without extra space and in O(n) runtime?
 *	
 *	Example:
 *	Input:
 *	[4,3,2,7,8,2,3,1]
 *	
 *	Output:
 *	[2,3]
 */

vector<int> findDuplicates(vector<int>& nums)
{
	vector<int> ans;
	for (int i = 0;i != nums.size();++i)
	{
		int index = abs(nums[i]) - 1;
		if (nums[index] < 0) ans.push_back(index + 1);
		else nums[index] = -nums[index];
	}
	return ans;
}

//和No.448相似
//若某个数出现两次，第一次将它所指的数变为负，第二次再找到它则直接push到ans中


/*
 *	如果这个问题要求找只出现过一次的那些数，可以如下
 *	即只要出现，就乘以-1，则出现两次的和没出现的都是正
 *	只有出现一次的是负
 */
vector<int> findSingles(vector<int>& nums)
{
	vector<int> ans;
	for (int i = 0;i != nums.size();++i)
	{
		int index = abs(nums[i]) - 1;
		nums[index] = -nums[index];
	}
	for (int i = 0;i != nums.size();++i)
	{
		if (nums[i] < 0) ans.push_back(i + 1); 
	}
	return ans;
}