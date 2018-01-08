/*
 *	164. Maximum Gap
 *	Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
 *	Try to solve it in linear time/space.
 *	Return 0 if the array contains less than 2 elements.
 *	You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
 */

//时间复杂度O(nlogn)
int maximumGap(vector<int>& nums)
{
	if (nums.size() < 2) return 0;
	sort(nums.begin(), nums.end());
	int len(nums.size());
	int ans(0);
	for (int i = 0;i < len - 1;++i)
	{
		ans = max(ans, nums[i + 1] - nums[i]);
	}
	return ans;
}

//用到基数排序(桶排序的一种)来进行排序可以达到O(n)