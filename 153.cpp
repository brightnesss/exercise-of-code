//leetcode No.153 Find Minimum in Rotated Sorted Array

/*
 *	Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 *	(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *	Find the minimum element.
 *	You may assume no duplicate exists in the array.
 */


//二分查找
int findMin(vector<int>& nums)
{
	int begin(0), end(nums.size() - 1);
	int mid = begin + (end - begin) / 2;
	while (begin < end)
	{
		if (nums[mid] > nums[end])
		{
			begin = mid + 1;
			mid = begin + (end - begin) / 2;
		}
		else
		{
			end = mid;
			mid = begin + (end - begin) / 2;
		}
	}
	return nums[begin];
}