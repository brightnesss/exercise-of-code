//leetcode No.174 Dungeon Game

/*
 *	The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid.
 *	Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.
 *	The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.
 *	Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; 
 *	other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).
 *	In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.

 *	Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.
 */

/*
 *	动态规划,用minHp数组表示到当前位置最少需要多少血
 *	不同是这次是从终点开始往起点前进,每次选择最少血的格子
 *	初始状态是:我们期望到达终点时只有1血,故minHp[m-1][n-1]=1-dungeon[m - 1][n - 1]
 *	若tmp<=0,说明dungeon这一格是正数,即有药,此时,进入这一格只需要1血
 *	否则,若tmp>0,说明dungeon这一格是负数,则需要足够血量进入这一格
 */

int calculateMinimumHP(vector<vector<int>>& dungeon)
{
	int m = dungeon.size(), n = dungeon[0].size();
	vector<vector<int>> minHp(m, vector<int>(n, 0));
	int tmp = 1 - dungeon[m - 1][n - 1];
	minHp[m - 1][n - 1] = tmp <= 0 ? 1 : tmp;
	for (int i = m - 2;i > -1;--i)
	{
		tmp = minHp[i + 1][n - 1] - dungeon[i][n - 1];
		minHp[i][n - 1] = tmp <= 0 ? 1 : tmp;
	}
	for (int i = n - 2;i > -2;--i)
	{
		tmp = minHp[m - 1][i + 1] - dungeon[m - 1][i];
		minHp[m - 1][i] = tmp <= 0 ? 1 : tmp;
	}
	for (int i = m - 2;i > -1;--i)
	{
		for (int j = n - 2;j > -1;--j)
		{
			tmp = min(minHp[i + 1][j], minHp[i][j + 1]) - dungeon[i][j];
			minHp[i][j] = tmp <= 0 ? 1 : tmp;
		}
	}
	return minHp[0][0];
}