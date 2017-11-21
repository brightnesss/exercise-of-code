//leetcode No.62 Unique Paths


/*
 *	A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 *	The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 *	How many possible unique paths are there?
 */


/*
 *	动态规划,用一个m*n的数组保存当前位置有多少种方法可以到达
 *	因为只能往下走或往右走,所以当前每一步都可以由左边到达或上面到达
 *	当前的状态vmap[i][j]=vmap[i-1][j]+vmap[i][j-1]
 *	初始状态是第一行都为1,它们都只能由原点向右走到达;第一列都为1,它们都只能由原点向下走到达
 */

int uniquePaths(int m, int n)
{
	vector<vector<int>> vmap(m, vector<int>(n, 1));	//第一行和第一列都是1
	for (int i = 1;i != m;++i)
	{
		for (int j = 1;j != n;++j)
		{
			vmap[i][j] = vmap[i - 1][j] + vmap[i][j - 1];
		}
	}
	return vmap[m - 1][n - 1];
}