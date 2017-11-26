/*
 *	238. Product of Array Except Self
 *	Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
 *	Solve it without division and in O(n).

 *	For example, given [1,2,3,4], return [24,12,8,6].

 *	Follow up:
 *	Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
 */

/*
 *	count记录nums中0的个数,product记录nums中除0外的乘积
 *	如果nums中有两个及两个以上的0,则ans应该全为0
 *	如果只有一个0,则除0外的乘积为product,其余的乘积都为0
 *	如果没有0,则除本身外的乘积为product除以本身
 */
vector<int> productExceptSelf(vector<int>& nums)
{
	int product(1), count(0);
	for (int num : nums)
	{
		if (num == 0) ++count;
		else product *= num;
	}
	vector<int> ans(nums.size(),0);
	if (count > 1) return vector<int>(nums.size(), 0);
	if (count == 1)
	{
		for (int i = 0;i != nums.size();++i)
		{
			if (nums[i] == 0) ans[i] = product;
		}
	}
	else
	{
		for (int i = 0;i != nums.size();++i)
		{
			ans[i] = product / nums[i];
		}
	}
	return ans;
}