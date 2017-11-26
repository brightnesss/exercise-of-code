/*
 *	169. Majority Element
 *	Given an array of size n, find the majority element. The majority element is the element that appears more than  floor(n/2)  times.
 *	You may assume that the array is non-empty and the majority element always exist in the array.
 */

/*
 *	排序法,如果一个数组中有一半以上是同一个数,那这个数组的中位数应该是就是这个数
 *	中位数一定是这个数(因为题目保证了majority element always exist in the array)	
 *	复杂度O(nlogn)
 */
int majorityElement(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	int len(nums.size());
	return nums[len/2];
}


/*
 *	也有可以使用map来计数的,速度可能会快一点
 *	复杂度O(n)
 */