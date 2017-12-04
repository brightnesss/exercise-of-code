/*
 *	213. House Robber II
 *	Note: This is an extension of House Robber.
 *	After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. 
 *	This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, 
 *	the security system for these houses remain the same as for those in the previous street.

 *	Given a list of non-negative integers representing the amount of money of each house, 
 *	determine the maximum amount of money you can rob tonight without alerting the police.
 */

/*
 *	This problem is a little tricky at first glance. However, if you have finished the House Robber problem, 
 *	this problem can simply be decomposed into two House Robber problems.
 *	Suppose there are n houses, since house 0 and n - 1 are now neighbors, 
 *	we cannot rob them together and thus the solution is now the maximum of

 *	Rob houses 0 to n - 2;
 *	Rob houses 1 to n - 1.

 *	The code is as follows. Some edge cases (n < 2) are handled explicitly.
 */

int subrob(vector<int>& nums)
{
	if (nums.empty()) return 0;
	if (nums.size() < 3) return *max_element(nums.begin(), nums.end());
	vector<int> bin(nums.size(), 0);
	bin[0] = nums[0], bin[1] = max(nums[0], nums[1]);
	for (int i = 2;i != bin.size();++i)
	{
		bin[i] = max(bin[i - 2] + nums[i], bin[i - 1]);
	}
	return *bin.rbegin();
}

int rob(vector<int>& nums)
{
	if (nums.empty()) return 0;
	if (nums.size() < 3) return *max_element(nums.begin(), nums.end());
	return max(subrob(vector<int>(nums.begin(), nums.end() - 1)), subrob(vector<int>(nums.begin() + 1, nums.end())));
}