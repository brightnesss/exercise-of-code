/*
 *	75. Sort Colors
 *	Given an array with n objects colored red, white or blue, 
 *	sort them so that objects of the same color are adjacent, 
 *	with the colors in the order red, white and blue.
 *	Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

 *	Note:
 *	You are not suppose to use the library's sort function for this problem.
 */

void sortColors(vector<int>& nums)
{
	int begin(0), end(nums.size());	//begin表示当前index,end表示数组长度
	int red(0), blue(end - 1);	//red为红色下一个该存放的位置,blue表示蓝色下一个该存放的位置
	while (begin <= blue)	//若begin>blue,说明整个数组都有序了
	{
		if (nums[begin] == 0)
		{
			swap(nums[begin], nums[red]);
			++red;
			++begin;	//red之前的都是红色的,是有序的
		}
		else if (nums[begin] == 1) ++begin;	//中间的是白色的
		else //nums[begin] == 2
		{
			swap(nums[begin], nums[blue]);
			--blue;	//尾部是蓝色的
		}
	}
}