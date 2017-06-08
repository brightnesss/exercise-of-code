//leetcode No.377 Combination Sum IV 

/*	Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.
 *	Example: 
 *	nums = [1, 2, 3]
 *	target = 4

 *	The possible combination ways are:
 *	(1, 1, 1, 1)
 *	(1, 1, 2)
 *	(1, 2, 1)
 *	(1, 3)
 *	(2, 1, 1)
 *	(2, 2)
 *	(3, 1)

 *	Note that different sequences are counted as different combinations.

 *	Therefore the output is 7.
 */


/*
 *	动态规划:若i为nums中的一个数,则对于target>i,有ans[target]=ans[target-nums[i]]
 *	初始状态:target为0时ans[0]=0;当target与nums中任一数相等时,ans[target]=1;
 *	对于其他任何状态,有两种情况:
 *	1. target<nums[0],此时ans[target]=0;
 *	2. target>=nums[0],此时,对该target遍历所有小于其的nums[i],ans[target]=sum(nums[target-nums[i]]) if nums[i]<=target
 */

int combinationSum4(vector<int>& nums, int target)
{
	if (nums.empty()) return 0;
	sort(nums.begin(), nums.end());
	if (target < nums[0]) return 0;
	vector<int> ans;
	for (int i = 0;i != nums[0];++i) ans.push_back(0);
	ans.push_back(1);
	for (int i = nums[0] + 1;i <= target;++i)
	{
		int tmp(0);
		for (int j : nums)
		{
			if (j > i) break;
			else
			{
				if (j == i) tmp += 1;
				else tmp += ans[i - j];
			}
		}
		ans.push_back(tmp);
	}
	return ans.back();
}