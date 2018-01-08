/*
 *	45. Jump Game II
 *	Given an array of non-negative integers, you are initially positioned at the first index of the array.
 *	Each element in the array represents your maximum jump length at that position.
 *	Your goal is to reach the last index in the minimum number of jumps.

 *	For example:
 *	Given array A = [2,3,1,1,4]
 *	The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

 *	Note:
 *	You can assume that you can always reach the last index.
 */

/*
 *	方法一：最原始的动态规划,超时.
 *	O(n^2)
 */

int jump(vector<int>& nums) 
{
	vector<int> bin(nums.size(), INT_MAX);
	bin[0] = 0;
	for (int i = 0;i != nums.size();++i)
	{
		for (int j = 1;j <= nums[i];++j)
		{
			if (i + j >= nums.size()) return *bin.rbegin();
			bin[i + j] = min(bin[i + j], bin[i] + 1);
		}
	}
	return *bin.rbegin();
}


/*
 *	方法二：我也不知道算什么...
 *	可以归纳为BFS,即step为树的层数,在step可以达到的位置都位于树的同一层
 *	O(n)
 */

/*
 *	迭代向前进
 *	在保证步数最少的情况下,前进最远的距离
 *	reach是在当前步数step下能走的最远的距离
 *	nextReach是在step + 1情况下能走最远的距离
 *	beginIndex是step步下的起始位置
 */
int jump(vector<int>& nums)
{
	if (nums.size() <= 1) return 0;
	int reach(nums[0]), step(1), beginIndex(0), nextReach(0);
	while (true)
	{
		if (reach + 1 >= nums.size()) return step;
		for (int i = beginIndex;i <= reach;++i)
		{
			if (i + nums[i] > reach) nextReach = max(nextReach, i + nums[i]);
		}
		beginIndex = reach + 1; //reach是在step下能走的最远地方,则step+1的起始位置为beginIndex
		reach = nextReach;
		++step;
	}
}

int jump(vector<int>& nums) 
{
    int ans(0),len(nums.size());
    int nextreach(0),reach(0);
    int i(0);
    while(i<len)
    {
        if (reach+1>=len) return ans;
        ++ans;
        while(i<len&&i<=reach)
        {
            nextreach=max(nextreach,i+nums[i]);
            ++i;
        }
        reach=nextreach;
    }
    return -1;
}
