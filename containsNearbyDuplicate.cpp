//leetcode No.219 Contains Duplicate II 

/*
 *	Given an array of integers and an integer k,
 *	find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k. 
 */

bool containsNearbyDuplicate(vector<int>& nums, int k)
{
	//还是一个sliding window的想法，不过是用set来保存
	unordered_set<int> bin;
	if (nums.empty() || k < 1) return false;
	k = k > nums.size() ? nums.size() : k;
	for (int i = 0;i != nums.size();++i)
	{
		if (i > k) bin.erase(nums[i - k - 1]);
		if (bin.find(nums[i]) == bin.end()) bin.insert(nums[i]);
		else return true;
	}
	return false;
}