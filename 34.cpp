/*
 *	34. Search for a Range
 *	Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.
 *	Your algorithm's runtime complexity must be in the order of O(log n).
 *	If the target is not found in the array, return [-1, -1].

 *	For example,
 *	Given [5, 7, 7, 8, 8, 10] and target value 8,
 *	return [3, 4].
 */


/*
 *	用两次二分查找,第一次找左边界,第二次找右边界
 *	不仅要找到相等,还要找到边界上的相等
 */

vector<int> searchRange(vector<int>& nums, int target)
{
	int begin(0), end(nums.size() - 1), mid, left(nums.size()), right(-1);
	while (begin <= end)
	{
		mid = (begin + end) / 2;
		if (nums[mid] < target) begin = mid + 1;
		else if (nums[mid] > target) end = mid - 1;
		else
		{
			left = mid < left ? mid : left;
			end = mid - 1;
		}
	}
	//若左边没有找到,就说明这个数就不存在
	if (left == nums.size()) return vector<int>{-1, -1};

	//第二次不用从0再开始,可以从左边边界开始
	begin = left, end = nums.size() - 1;
	while (begin <= end)
	{
		mid = (begin + end) / 2;
		if (nums[mid] < target) begin = mid + 1;
		else if (nums[mid] > target) end = end - 1;
		else
		{
			right = mid > right ? mid : right;
			begin = mid + 1;
		}
	}
	return vector<int>{left, right};
}