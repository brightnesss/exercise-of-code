//leetcode No.448 Find All Numbers Disappeared in an Array 

/*
 *	Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
 *	Find all the elements of [1, n] inclusive that do not appear in this array.
 *	Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
 *	Example: 
 *	
 *	Input:
 *	[4,3,2,7,8,2,3,1]
 *	
 *	Output:
 *	[5,6]
 */

vector<int> findDisappearedNumbers(vector<int>& nums)
{
	vector<int> ans;
	for (int i = 0;i != nums.size();++i)
	{
		int index = abs(nums[i]) - 1;
		nums[index] = nums[index] > 0 ? -nums[index] : nums[index];
	}
	for (int i = 0;i != nums.size();++i)
	{
		if (nums[i] > 0) ans.push_back(i + 1);
	}
	return ans;
}

//数据index既是一个数，也是顺序排列时它在数组中的下标
//将该下标所指数乘以-1变为负
//第一次循环后只有那些没有出现过的数字所指的位置为正