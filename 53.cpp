/*
 *	53. Maximum Subarray
 *	Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
 *	For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
 *	the contiguous subarray [4,-1,2,1] has the largest sum = 6.
 */

//简单的动态规划
int maxSubArray(vector<int>& nums)
{
	if (nums.empty()) return 0;
	vector<int> bin(nums.size(), INT_MIN);
	bin[0] = nums[0];
	for (int i = 1;i < nums.size();++i)
	{
		bin[i] = max(bin[i - 1] + nums[i], nums[i]);
	}
	return *max_element(bin.begin(), bin.end());
}