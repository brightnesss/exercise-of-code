/*
 *	Given an unsorted integer array, find the first missing positive integer.

 *	For example,
 *	Given [1,2,0] return 3,
 *	and [3,4,-1,1] return 2.

 *	Your algorithm should run in O(n) time and uses constant space.
 */


//运用index的信息来做记录,使得每一个正数都位于数组中nums[i]-1的位置,即使得数组是从1开始排列的,则从左数缺的第一个就是所求值
int firstMissingPositive(vector<int>& nums)
{
	int i(0);
	while (i < nums.size())
	{
		if (nums[i] > 0 && nums[i] < nums.size())	//nums[i]>0保证是个正数, nums[i]<nums.size() 保证nums[i]-1是个合法的index值
		{
			if (nums[i] != nums[nums[i] - 1]) swap(nums[i], nums[nums[i] - 1]);	//如果这个位置上就是这个数,则不需要交换
			else ++i;
		}
		else ++i;
	}
	for (int i = 0;i != nums.size();++i)
	{
		if (nums[i] != i + 1) return i + 1;	//排列之后,数组的每一位应该都是满足nums[i]==i+1,不满足的数就是所求值
	}
	return nums.size() + 1;//若遍历结束,说明本来就是有序的,则缺少最大的数
}