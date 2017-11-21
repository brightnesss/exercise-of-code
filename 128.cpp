/*
 *	128. Longest Consecutive Sequence
 *	Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
 *	For example,
 *	Given [100, 4, 200, 1, 3, 2],
 *	The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

 *	Your algorithm should run in O(n) complexity.
 */

/*
 *	排序
 *	时间复杂度O(nlogn)
 */
int longestConsecutive(vector<int>& nums)
{
	if (nums.empty()) return 0;
	sort(nums.begin(), nums.end());
	int maxLen(INT_MIN), curLen(1);
	for (int i = 1;i != nums.size();++i)
	{
		if (nums[i] == nums[i - 1]) continue;
		else if (nums[i] == nums[i - 1] + 1) ++curLen;
		else
		{
			maxLen = max(maxLen, curLen);
			curLen = 1;
		}
	}
	return max(maxLen, curLen);
}

/*
 *	使用set来存放nums,并同时依赖set的性质进行快速的查找
 *	时间复杂度O(n),空间复杂度O(n)
 */

int longestConsecutive(vector<int>& nums)
{
	if (nums.empty()) return 0;
	set<int> bin(nums.begin(), nums.end());
	int maxLen(INT_MIN), curLen(1);
	for (int num : bin)
	{
		if (bin.find(num - 1) == bin.end())
		{
			while (bin.find(num + 1) != bin.end())
			{
				++num;
				++curLen;
			}
			maxLen = max(maxLen, curLen);
			curLen = 1;
		}
	}
	return max(maxLen, curLen);
}