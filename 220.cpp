/*
 *	220. Contains Duplicate III
 *	Given an array of integers, find out whether there are two distinct indices i and j in the array 
 	such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.
 */

/*
 *	采用一个windows来最多存储(nums[i]...nums[i+k-1]),当刚开始建立windows的时候,里面的数的个数还是较少的
 *	新来一个数nums[i],相当于要在windows中找一个数x,使得|x-nums[i]|<=t
 	展开绝对值,得到-t<=x-nums[i]<=t
 	1)左边为x>=nums[i]-t,可以通过windows.lower_bound来寻找x
 	2)右边为x-nums[i]<=t,若1)找到了x,则可以进行进一步的判断
 */
bool containsNearbyAlmostDuplicate_v2(vector<int>& nums, int k, int t)
{
	if (nums.empty()) return false;
	set<int> windows;
	int len(nums.size());
	for (int i=0;i!=len;++i)
	{
		if (i>k) windows.erase(nums[i-k-1]);	//如果windows中已经有k+1个数了,就需要删掉一个最早的
		auto pos=windows.lower_bound(nums[i]-t);
		if (pos!=windows.end()&&*pos-nums[i]<=t) return true;
		windows.insert(nums[i]);
	}
	return false;
}