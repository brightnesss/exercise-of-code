/*
 *	47. Permutations II
 *	Given a collection of numbers that might contain duplicates, return all possible unique permutations.

 *	For example,
	[1,1,2] have the following unique permutations:
	[
  	 [1,1,2],
  	 [1,2,1],
  	 [2,1,1]
	]
 */

/*
 *	
 */

void subPermuteUnique(vector<int> nums, int begin, const int& len, vector<vector<int>>& ans)
{
	if (begin == len - 1)
	{
		ans.push_back(nums);
		return;
	}
	for (int i = begin;i != len;++i)
	{
		if (i > begin&&nums[i] == nums[begin]) continue;	//重复
		else
		{
			swap(nums[i], nums[begin]);
			subPermuteUnique(nums, begin + 1, len, ans);
		}
	}
}

vector<vector<int>> permuteUnique(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	vector<vector<int>> ans;
	int len(nums.size());
	subPermuteUnique(nums, 0, len, ans);
	return ans;
}