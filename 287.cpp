//leetcode No.287 Find the Duplicate Number 

/*
 *	Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one. 
 *	Note:
 *	You must not modify the array (assume the array is read only).
 *	You must use only constant, O(1) extra space.
 *	Your runtime complexity should be less than O(n2).
 *	There is only one duplicate number in the array, but it could be repeated more than once.
 */


/*
 *	用二分查找法
 *	对于一组分布在low...high的数组中,可以令中间数为mid = low + (high - low) / 2
 *	在数组nums中查找,若小于等于mid的数的个数count大于mid,则重复数字一定在low...mid间
 *	若count小于等于mid,则重复数字在mid+1...high之间
 *	更新low或high,重复迭代,直到low和high相等
 *	每次需要遍历一遍nums,复杂度为O(n);二分查找复杂度O(longn);故总复杂度为O(nlogn)
 */

/*
 *	这里的二分查找和一般的不一样
 *	不再是对nums[index]比较,而是直接比较index
 */

int findDuplicate(vector<int>& nums)
{
	int begin(1), end(nums.size() - 1), mid, count;
	while (begin < end)
	{
		mid = (begin + end) / 2;	//不比较nums[mid],而是mid
		count = 0;
		for (int num : nums)
		{
			if (num <= mid) ++count;
		}
		if (count > mid) end = mid;
		else begin = mid + 1;
	}
	return begin;
}