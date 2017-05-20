//leetcode No.477 Total Hamming Distance 

/*
 *	The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
 *	Now your job is to find the total Hamming distance between all pairs of the given numbers. 
 */

/*
 *	每一个数都可以写成32位的bit流
 *	可以每次都遍历每一个数的位,检查在这个位上总共有多少个1,多少个0,假设有count个数在该位上为1,则有n-count个数在该位上为0,其中n为nums的长度
 *	则在该位上产生的Hamming距离为:C(1,count) * C(1,(n-count)) = count * (n-count)
 *	遍历完32位的bit流即可
 *	将复杂度从O(n*n)降到了O(32*n)
 */

int totalHammingDistance(vector<int>& nums)
{
	int ans(0), n(nums.size()), count(0);
	for (int i = 0;i != 32;++i)
	{
		count = 0;
		for (int j : nums)
		{
			count += (j >> i) & 1;
		}
		ans += count*(n - count);
	}
	return ans;
}