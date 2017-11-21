/* 
 *	154. Find Minimum in Rotated Sorted Array II
 *	Follow up for "Find Minimum in Rotated Sorted Array":
 *	What if duplicates are allowed?

 *	Would this affect the run-time complexity? How and why?
 *	Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

 *	(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *	Find the minimum element.

 *	Note: The array may contain duplicates.
 */

int findMin(vector<int>& nums)
{
	int begin(0), end(nums.size() - 1);
	int mid;
	while (begin < end)
	{
		mid = begin + (end - begin) / 2;
		if (nums[begin] == nums[mid] && nums[mid] == nums[end])	//加上这句即可,即如果判断到有重叠的数,则begin和end都向中间移动
		{
			++begin;
			--end;
		}
		else if (nums[mid] >= nums[begin])
		{
			if (nums[mid] <= nums[end]) return nums[begin];
			else
			{
				begin = mid + 1;
			}
		}
		else
		{
			++begin;
			end = mid;
		}
	}
	return nums[begin];
}