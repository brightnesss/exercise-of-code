//leetcode No.491 Increasing Subsequences

/*
 *	Given an integer array, your task is to find all the different possible increasing subsequences of the given array, and the length of an increasing subsequence should be at least 2 .

 *	Example:
 *	Input: [4, 6, 7, 7]
 *	output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]

 *	Note:
 *	The length of the given array will not exceed 15.
 *	The range of integer in the given array is [-100,100].
 *	The given array may contain duplicates, and two equal integers should also be considered as a special case of increasing sequence.
 */

void findSubsequences(set<vector<int>> &bin, vector<int> &nums, vector<int> tmp, int begin)
{
	if (begin >= nums.size()) return;
	for (int i = begin;i != nums.size();++i)
	{
		if (tmp.empty()) tmp.push_back(nums[i]);
		else if (nums[i] >= tmp.back()) tmp.push_back(nums[i]);
		if (tmp.size() > 1) bin.insert(tmp);
		findSubsequences(bin, nums, tmp, i + 1);
		tmp.pop_back();
	}
}

vector<vector<int>> findSubsequences(vector<int>& nums)
{
	if (nums.empty()) return vector<vector<int>>();
	sort(nums.begin(), nums.end());
	set<vector<int>> bin;
	findSubsequences(bin, nums, vector<int>(), 0);
	vector<vector<int>> ans(bin.begin(), bin.end());
	return ans;
}