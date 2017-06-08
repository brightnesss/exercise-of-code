//leetcode No.63 Unique Paths II

/*
 *	Follow up for "Unique Paths":
 *	Now consider if some obstacles are added to the grids. How many unique paths would there be?
 *	An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 */

/*
 *	动态规划,遇到陷阱则该位置的值为0,即不可能到达也不可能从这里出发
 */

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
	int m = obstacleGrid.size(), n = obstacleGrid[0].size();
	vector<vector<int>> vmap(m, vector<int>(n, 0));
	for (int i = 0;i != m;++i)
	{
		if (obstacleGrid[i][0] == 0) vmap[i][0] = 1;
		else break;
	}
	for (int i = 1;i != n;++i)
	{
		if (obstacleGrid[0][i] == 0) vmap[0][i] = 1;
		else break;
	}
	for (int i = 1;i != m;++i)
	{
		for (int j = 1;j != n;++j)
		{
			if (obstacleGrid[i][j] == 0) vmap[i][j] = vmap[i - 1][j] + vmap[i][j - 1];
			else vmap[i][j] = 0;
		}
	}
	return vmap[m - 1][n - 1];
}