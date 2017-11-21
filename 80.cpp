/*
 *	80. Remove Duplicates from Sorted Array II
 *	Follow up for "Remove Duplicates":
 *	What if duplicates are allowed at most twice?

 *	For example,
 *	Given sorted array nums = [1,1,1,2,2,3],
 *	Your function should return length = 5, 
 *	with the first five elements of nums being 1, 1, 2, 2 and 3. 
 *	It doesn't matter what you leave beyond the new length.
 */

int removeDuplicates(vector<int>& nums)
{
	if (nums.size() <= 1) return nums.size();
	int it(1), count(1);
	for (int i = 1;i != nums.size();++i)
	{
		if (nums[i] == nums[it - 1])
		{
			++count;
			if (count <= 2)	//set 2 to any value to match the problem: allowed at most x times
			{
				nums[it] = nums[i];
				++it;
			}
			else continue;
		}
		else
		{
			count = 1;
			nums[it] = nums[i];
			++it;
		}
	}
	return it;
}