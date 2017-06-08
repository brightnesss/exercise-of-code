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

int findDuplicate(vector<int>& nums)
{
	if (nums.empty()) return 0;
	int low(1), high(nums.size() - 1);
	while (low < high)
	{
		int count(0);
		int mid = low + (high - low) / 2;
		for (int i = 0;i != nums.size();++i) if (nums[i] <= mid) ++count;
		if (count <= mid) low = mid + 1;
		else high = mid;
	}
	return low;
}