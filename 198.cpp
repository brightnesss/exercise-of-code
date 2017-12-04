/*
 *	198. House Robber
 *	You are a professional robber planning to rob houses along a street. 
 *	Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them 
 *	is that adjacent houses have security system connected and it will automatically contact the police 
 *	if two adjacent houses were broken into on the same night.

 *	Given a list of non-negative integers representing the amount of money of each house, 
 *	determine the maximum amount of money you can rob tonight without alerting the police.
 */

/*
 *	用一个vector来存储截止到位置
 */

int rob(vector<int>& nums)
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