/*
 *	Given an array and a value, remove all instances of that value in-place and return the new length.
 *	Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
 *	The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 *	Example:
 *	Given nums = [3,2,2,3], val = 3,
 *	Your function should return length = 2, with the first two elements of nums being 2.
 */


int removeElement(vector<int>& nums, int val)
{
	if (nums.empty()) return 0;
	int i(0), j(0);
	while (j < nums.size())
	{
		if (nums[j] == val) ++j;
		else
		{
			nums[i] = nums[j];
			++i;
			++j;
		}
	}
	return i;
}



//当数组中等于val的值很少时,这种方法移动的次数更少
int removeElement_v2(vector<int>& nums, int val)
{
	int i(0), end(nums.size() - 1), diff(0);
	while (i <= end)
	{
		if (nums[i] == val)
		{
			swap(nums[i], nums[end]);
			--end;
			++diff;
		}
		else ++i;
	}
	return nums.size() - diff;
}