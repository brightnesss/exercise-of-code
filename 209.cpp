/*
 *	209. Minimum Size Subarray Sum
 *	Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. 
 *	If there isn't one, return 0 instead.

 *	For example, given the array [2,3,1,2,4,3] and s = 7,
 *	the subarray [4,3] has the minimal length under the problem constraint.
 */

/*
 *	暴力法,有点类似BFS
 *	先令数组中每一个数为单独的和
 *	从它们开始,每次与它们这个数的右边的数相加得到新的和,与此同时,最终结果也会+1
 *	复杂度O(n2)
 */
int minSubArrayLen(int s, vector<int>& nums)
{
	if (nums.empty()) return 0;
	queue<pair<int,int>> bin;	//pair<int,int>的first存储目前到目标s还有多少的距离,若first<=0,说明这个subarray的和已经达到s了;second表示目前这个subarray的最右边边界
	int ans(1);
	for (int i = 0;i != nums.size();++i)
	{
		bin.push(make_pair(s - nums[i], i)); //初始时,bin的每一个组合是有nums中每个数构成的
	}
	int len(bin.size());
	pair<int, int> front;
	while (!bin.empty())
	{
		for (int i = 0;i != len;++i)
		{
			front = bin.front();
			bin.pop();
			if (front.first <= 0) return ans; //若已经达到了s,返回当前的ans,即subarray的大小
			if (front.second + 1 != nums.size()) bin.push(make_pair(front.first - nums[front.second + 1], front.second + 1)); //如果subarray的右边界没有到nums的边界的话,将这个subarray向右扩展一位
		}
		len = bin.size();
		++ans; 
	}
	return 0;
}

/*
 *	Using 2 pointers [Accepted]
 *	Intuition
 *	Until now, we have kept the starting index of subarray fixed, and found the last position. 
 *	Instead, we could move the starting index of the current subarray as soon as we know that no better could be done with this index as the starting index. 
 *	We could keep 2 pointer,one for the start and another for the end of the current subarray, 
 *	and make optimal moves so as to keep the sum greater than ss as well as maintain the lowest size possible.

 *	Algorithm

 *	Initialize left pointer to 0 and \text{sum}sum to 0
 *	Iterate over the nums:
 *	Add nums[i] to sum
 *	While sum is greater than or equal to ss:
 *	Update ans=min(ans,i+1−left), where i+1−left is the size of current subarray
 *	It means that the first index can safely be incremented, since, the minimum subarray starting with this index with sum≥s has been achieved
 *	Subtract nums[left] from sum and increment left
 */

int minSubArrayLen(int s, vector<int>& nums)
{
	if (nums.empty()) return 0;
	int ans(INT_MAX),len(nums.size()),left(0),curSum(0);
	for (int i=0;i!=len;++i)
	{
		curSum+=nums[i];
		while(curSum>=s)
		{
			ans=min(ans,i+1-left);
			curSum-=nums[left];
			++left;
		}
	}
	return ans==INT_MAX?0:ans;
}