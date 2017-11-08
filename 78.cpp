//leetcode No.78 Subsets

/*
 *	Given a set of distinct integers, nums, return all possible subsets.
 *	Note: The solution set must not contain duplicate subsets.

 *	For example,
 *	If nums = [1,2,3], a solution is:

	[
  		[3],
  		[1],
  		[2],
  		[1,2,3],
  		[1,3],
  		[2,3],
  		[1,2],
  		[]
	]
 */

//参考leetocde No.46的做法

void subsets(vector<vector<int>> &ans, vector<int> &nums, vector<int> tmp, int begin)
{
	if (tmp.size() >= nums.size() - 1) return; //只递归到真子集
	for (int i = begin;i < nums.size();++i)
	{
		tmp.push_back(nums[i]);
		ans.push_back(tmp);
		subsets(ans, nums, tmp, i + 1);
		tmp.pop_back(); //需要回退一步
	}
}

vector<vector<int>> subsets(vector<int>& nums)
{
	vector<vector<int>> ans;
	ans.push_back(vector<int>());
	if (nums.empty()) return ans;
	ans.push_back(nums);
	subsets(ans, nums, vector<int>(), 0);
	return ans;
}