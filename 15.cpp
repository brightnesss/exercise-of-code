/*
 *	Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 *	Note: The solution set must not contain duplicate triplets.
 *	For example, given array S = [-1, 0, 1, 2, -1, -4],

 *	A solution set is:
	[
  	 [-1, 0, 1],
  	 [-1, -1, 2]
	]
 */

/*
 *	两点法
 *	先排序,可以解决一部分的重复问题
 *	对于一个数,nums[i],找到两个数的和为-nums[i]即可
 *	令a = i + 1, b = end - 1,为两点的初始位置
 *	若nums[a] + nums[b] < -nums[i], 说明小值太小, ++a
 *	若nums[a] + nums[b] > -nums[i], 说明大值太大, --b

 *	while (nums[a] == nums[a - 1]) ++a;
	while (nums[b] == nums[b + 1]) --b;
 *	是为了防止出现[-2,0,0,2,2]这样的情况
 *	一次答案出现后,保证相同的数字不再出现,因为三个数中只要有两个数相同,则三个数都相同
 */


vector<vector<int>> threeSum(vector<int>& nums)
{
	vector<vector<int>> ans;
	const int end(nums.size());
	sort(nums.begin(), nums.end());
	int a(0), b(0), target(0);
	for (int i = 0;i != end;++i)
	{
		if (i > 0 && nums[i] == nums[i - 1]) continue;
		a = i + 1;
		b = end - 1;
		target = -nums[i];
		while (a < b)
		{
			if (nums[a] + nums[b] < target) ++a;
			else if (nums[a] + nums[b] > target) --b;
			else
			{
				if (nums[a]==nums[a-1]) 
				ans.push_back(vector<int>{nums[i], nums[a], nums[b]});
				++a;
				--b;
				while (nums[a] == nums[a - 1]) ++a;
				while (nums[b] == nums[b + 1]) --b;
			}
		}
	}
	return ans;
}