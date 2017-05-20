// leetcode No.26 Remove Duplicates from Sorted Array 

/*
 *	Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
 *	Do not allocate extra space for another array, you must do this in place with constant memory. 
 *	For example,
 *	Given input array nums = [1,1,2], 
 *	Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length. 
 */

int removeDuplicates(vector<int>& nums)
{
	int pos(0), i(0); //pos指向没有重复的数组的位置，i指向原数组当前位置
	if (nums.empty()) return pos;
	++pos; //第一个数肯定要入
	for (;i != nums.size();++i)
	{
		if (nums[i] != nums[pos - 1])
		{
			//若nums[i]没有重复
			nums[pos] = nums[i]; //保存
			++pos; //pos下移
		}
	}
	vector<int>::iterator it = nums.begin() + pos;
	nums.erase(it, nums.end()); //删除后面的重复
	return pos;
}