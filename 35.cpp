// leetcode No.35 Search Insert Position

/*
 *	Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
 *	You may assume no duplicates in the array.
 */

int searchInsert(vector<int>& nums, int target)
{
	if (nums.empty()) return 0;
	for (int i = 0;i != nums.size();++i)
	{
		if (nums[i] >= target) return i;
		else continue;
	}
	return nums.size();
}