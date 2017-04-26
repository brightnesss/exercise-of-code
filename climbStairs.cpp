//leetcode No.Climbing Stairs 

/*
 *	You are climbing a stair case. It takes n steps to reach to the top.
 *	Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top? 
 *	Note: Given n will be a positive integer. 
 */

//动态规划
//梯子长度为n的步数=梯子长度为n-1的步数(climb 1 step)+梯子长度为n-2的步数(climb 2 steps)
int climbStairs(int n)
{
	if (n == 0) return 0;
	else if (n == 1) return 1;
	else if (n == 2) return 2;
	vector<int> ans = { 0,1,2 };
	for (int i = 3;i <= n;++i) ans.push_back(ans[i - 1] + ans[i - 2]);
	return ans[n];
}