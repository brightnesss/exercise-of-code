//leetcode No.46 Permutations 

/*
 *	Given a collection of distinct numbers, return all possible permutations. 
 *	For example,
 *	[1,2,3] have the following permutations:
	[
   		[1,2,3],
  		[1,3,2],
  		[2,1,3],
  		[2,3,1],
  		[3,1,2],
  		[3,2,1]
	]
 */


//非常暴力的解法
void permute(vector<vector<int>> &ans, vector<int> nums, vector<int> tmp)
{
	if (nums.empty()) { ans.push_back(tmp);return; }
	for (int i = 0;i != nums.size();++i)
	{
		tmp.push_back(nums[i]);
		vector<int> nextnum = nums;
		nextnum.erase(nextnum.begin() + i, nextnum.begin() + i + 1);
		permute(ans, nextnum, tmp);
		tmp.pop_back();
	}
}

vector<vector<int>> permute(vector<int>& nums)
{
	vector<vector<int>> ans;
	vector<int> tmp;
	permute(ans, nums, tmp);
	return ans;
}

//用交换替代删除,效率会高一点
void permute(vector<vector<int>> &ans, vector<int> &nums, int begin)
{
	if (begin == nums.size()) { ans.push_back(nums);return; }
	for (int i = begin;i != nums.size();++i)
	{
		swap(nums[i], nums[begin]);
		permute(ans, nums, begin + 1);
		swap(nums[i], nums[begin]);
	}
}

vector<vector<int>> permute(vector<int>& nums)
{
	vector<vector<int>> ans;
	vector<int> tmp;
	permute(ans, nums, 0);
	return ans;
}