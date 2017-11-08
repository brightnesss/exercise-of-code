// leetcode No.35 Search Insert Position

/*
 *	Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
 *	You may assume no duplicates in the array.

 	Example 1:
	Input: [1,3,5,6], 5
	Output: 2

	Example 2:
	Input: [1,3,5,6], 2
	Output: 1

	Example 3:
	Input: [1,3,5,6], 7
	Output: 4

	Example 4:
	Input: [1,3,5,6], 0
	Output: 0
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

int searchInsert_v2(vector<int>& nums, int target)
{
	if (target <= nums[0]) return 0;
	if (target > nums[nums.size() - 1]) return nums.size();
	int begin(0), end(nums.size() - 1), mid;
	while (begin <= end)
	{
		mid = (begin + end) / 2;
		if (nums[mid] == target) return mid;
		else if (nums[mid] > target) end = mid - 1;
		else begin = mid + 1;
	}
	if (nums[begin] > target) return begin;
	else return begin + 1;
}

int searchInsert_v3(vector<int>& nums, int target) {
    int low = 0, high = nums.size()-1;

    // Invariant: the desired index is between [low, high+1]
    while (low <= high) {
        int mid = low + (high-low)/2;

        if (nums[mid] < target)
            low = mid+1;
        else
            high = mid-1;
    }

    // (1) At this point, low > high. That is, low >= high+1
    // (2) From the invariant, we know that the index is between [low, high+1], so low <= high+1. Follwing from (1), now we know low == high+1.
    // (3) Following from (2), the index is between [low, high+1] = [low, low], which means that low is the desired index
    //     Therefore, we return low as the answer. You can also return high+1 as the result, since low == high+1
    return low;
}