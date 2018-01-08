/*
 *	239. Sliding Window Maximum
 *	Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. 
 	You can only see the k numbers in the window. Each time the sliding window moves right by one position.

 *	For example,
	Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

	Window position                Max
	---------------               -----
	[1  3  -1] -3  5  3  6  7       3
 	 1 [3  -1  -3] 5  3  6  7       3
 	 1  3 [-1  -3  5] 3  6  7       5
 	 1  3  -1 [-3  5  3] 6  7       5
 	 1  3  -1  -3 [5  3  6] 7       6
 	 1  3  -1  -3  5 [3  6  7]      7
	Therefore, return the max sliding window as [3,3,5,5,6,7].

 *	Note: 
	You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.
 */

//方法一,使用multiset
//multiset的最后一元素总能保证是最大的
vector<int> maxSlidingWindow(vector<int>& nums, int k) 
{
	vector<int> ans;
	if (nums.empty() || k <= 0) return ans;
	int begin(0), end(0), len(nums.size());
	multiset<int> mset;
	while (end != k)
	{
		mset.emplace(nums[end++]);
	}
	ans.push_back(*mset.rbegin());
	while (end < len)
	{
		mset.erase(mset.find(nums[begin++]));
		mset.emplace(nums[end++]);
		ans.push_back(*mset.rbegin());
	}
	return ans;
}

//方法二,使用双向队列
//保证双向队列中第一个元素是当前最大的
vector<int> maxSlidingWindow_v2(vector<int>& nums, int k)
{
	vector<int> ans;
	if (nums.empty() || k <= 0) return ans;
	int begin(0), end(0), len(nums.size());
	deque<pair<int, int>> dq;	//pair<int,int> 存储<index,value>
	while (end < k)
	{
		while (!dq.empty() && nums[end] >= dq.back().second) dq.pop_back();	//若当前这个大,一直从后方弹出小的元素直到前面的比它大
		dq.push_back(make_pair(end, nums[end]));
		++end;
	}
	ans.push_back(dq.front().second);
	while (end < len)
	{
		++begin;
		while (!dq.empty() && dq.front().first < begin) dq.pop_front();	//若前面的元素已经不在windows中了,弹出
		while (!dq.empty() && nums[end] >= dq.back().second) dq.pop_back();	//加入新的元素
		dq.push_back(make_pair(end, nums[end]));
		++end;
		ans.push_back(dq.front().second);	//将最大的压入ans
	}
	return ans;
}