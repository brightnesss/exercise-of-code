/*
 *	Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? 
 *	Find all unique quadruplets in the array which gives the sum of target.
 *	Note: The solution set must not contain duplicate quadruplets.
 *	For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.
 
 *	A solution set is:
	[
   	 [-1,  0, 0, 1],
  	 [-2, -1, 1, 2],
  	 [-2,  0, 0, 2]
	]
 */


vector<vector<int>> fourSum(vector<int>& nums, int target)
{
	int end(nums.size());
	if (end < 4) return vector<vector<int>>{};
	sort(nums.begin(), nums.end());
	vector<vector<int>> ans;
	for (int i = 0;i < end - 3;++i)
	{
		if (i > 0 && nums[i] == nums[i - 1]) continue;
		for (int j = i + 1;j < end - 2;++j)
		{
			if (j > i + 1 && nums[j] == nums[j - 1]) continue;
			int m(j + 1), n(end - 1), sub_target(target - nums[i] - nums[j]);
			while (m < n)
			{
				if (m > j + 1 && nums[m] == nums[m - 1])
				{
					++m;
					continue;
				}
				if (nums[m] + nums[n] < sub_target) ++m;
				else if (nums[m] + nums[n] > sub_target) --n;
				else
				{
					ans.push_back(vector<int>{nums[i], nums[j], nums[m], nums[n]});
					++m;
					--n;
				}
			}
		}
	}
	return ans;
}