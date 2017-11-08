//leetcode No.215 Kth Largest Element in an Array

/*
 *	Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

 *	For example,
 *	Given [3,2,1,5,6,4] and k = 2, return 5.

 *	Note: 
 *	You may assume k is always valid, 1 ≤ k ≤ array's length.
 */

//用快速排序的方法
int findKthLargest(vector<int>& nums, int left, int right)
{
	int begin(left), end(right);
	int flag(nums[begin]);
	while (begin < end)
	{
		while (begin < end && nums[end] >= flag) --end;
		if (begin < end) nums[begin++] = nums[end];
		while (begin < end && nums[begin] <= flag) ++begin;
		if (begin < end) nums[end--] = nums[begin];
	}
	nums[begin] = flag;
	return begin + 1;
}

int findKthLargest(vector<int>& nums, int k)
{
	if (nums.size() == 1) return nums[0];
	k = nums.size() - k + 1;
	int left(0), right(nums.size() - 1);
	while (true)
	{
		int rank = findKthLargest(nums, left, right);
		if (rank == k) return nums[k - 1];
		if (rank > k) right = rank - 1;
		else left = rank;
	}
}

//用最大堆的方法
int findKthLargest(vector<int>& nums, int k) 
{
    priority_queue<int> pq(nums.begin(), nums.end());
    for (int i = 0; i < k - 1; i++) pq.pop(); 
    return pq.top();
}