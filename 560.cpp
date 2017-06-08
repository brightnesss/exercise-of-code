//leetcode No.560 Subarray Sum Equals K 

/*
 *	Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

 *	Example 1:
 *	Input:nums = [1,1,1], k = 2
 *	Output: 2

 *	Note:
 *	The length of the array is in range [1, 20,000].
 *	The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].
 */


/*
 *	we know the key to solve this problem is SUM[i, j]. So if we know SUM[0, i - 1] and SUM[0, j], then we can easily get SUM[i, j]. 
 *	To achieve this, we just need to go through the array, calculate the current sum and save number of all seen PreSum to a HashMap. 
 *	Time complexity O(n), Space complexity O(n).
 */

int subarraySum(vector<int>& nums, int k)
{
	int ans(0), sum(0);
	map<int, int> bin;	 //map<presum,count> bin;
	for (int x : nums)
	{
		++bin[sum]; //有多个连续子序列和为sum
		sum += x;
		if (bin.find(sum - k) != bin.end()) ans += bin[sum - k];
	}
	return ans;
}