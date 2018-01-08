/*
 *	Given an array of non-negative integers, you are initially positioned at the first index of the array.
 *	Each element in the array represents your maximum jump length at that position.
 *	Determine if you are able to reach the last index.

 *	For example:
	A = [2,3,1,1,4], return true.
	A = [3,2,1,0,4], return false.
 */

//计算最远能够到达的距离,若这个距离大于了整个数组的大小,则说明可以到达,否则不能到达
bool canJump(vector<int>& nums)
{
	int maxReach(nums[0]), int i(0);
	for (;i <= maxReach;++i)
	{
		if (nums[i] + i > maxReach) maxReach = nums[i] + i;
		if (maxReach + 1 >= nums.size()) return true;
	}
	return false;
}

bool canJump(vector<int>& nums) 
{
    vector<bool> bin(nums.size(),false);
    bin[0]=true;
    int maxLen(0);
    int maxLentmp(0);
    for (int i=0;i!=nums.size();++i)
    {
        if (bin[i]==false) return false;
        maxLentmp=i+nums[i];
        if (maxLen>=nums.size()||maxLentmp>=nums.size()) return true;
        if (maxLentmp>maxLen)
        {
            for (int j=maxLen;j<=maxLentmp;++j) bin[j]=true;
            maxLen=maxLentmp;
        }
    }
    return bin.back();
}