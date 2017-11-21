/*
 *	90. Subsets II
 *	Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).
 *	Note: The solution set must not contain duplicate subsets.

 *	For example,
 *	If nums = [1,2,2], a solution is:

	[
  	 [2],
  	 [1],
  	 [1,2,2],
  	 [2,2],
  	 [1,2],
  	 []
	]
 */


/*
 *	迭代法
 *	采用了pos来记录当重复发生时应该开始的位置
 *	若nums[i]!=nums[i-1],应该从ans的开头位置开始遍历
 *	若nums[i]==nums[i-1],则从pos开始遍历,这样就跳过了之前会发生重复的位置
 */
vector<vector<int>> subsetsWithDup(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	vector<vector<int>> ans(1, vector<int>());
	int pos;
	for (int i = 0;i != nums.size();++i)
	{
		if (i == 0)
		{
			ans.push_back(vector<int>(1, nums[i]));
			pos = 1;
		}
		else
		{
			if (nums[i] == nums[i - 1])
			{
				int n = ans.size();
				for (int j = pos;j != n;++j)
				{
					ans.push_back(ans[j]);
					ans.back().push_back(nums[i]);
				}
				pos = n;
			}
			else
			{
				int n = ans.size();
				for (int j = 0;j != n;++j)
				{
					ans.push_back(ans[j]);
					ans.back().push_back(nums[i]);
				}
				pos = n;
			}
		}
	}
	return ans;
}