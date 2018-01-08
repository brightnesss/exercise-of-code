/*
 *	200. Number of Islands
 *	Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. 
 *	An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
 *	You may assume all four edges of the grid are all surrounded by water.

 *	Example 1:
	11110
	11010
	11000
	00000
	Answer: 1

 *	Example 2:
	11000
	11000
	00100
	00011
	Answer: 3

 *	相当于是找有几个连通分量
 */

//深度优先搜索
int numIslands(vector<vector<char>>& grid)
{
	if (grid.empty() || grid[0].empty()) return 0;
	int m(grid.size()), n(grid[0].size());
	vector<vector<bool>> visited(m, vector<bool>(n, false));
	stack<pair<int, int>> bin;
	int row, col, ans(0);
	for (int i = 0;i != m;++i)
	{
		for (int j = 0;j != n;++j)
		{
			if (grid[i][j] == '0') continue;
			else
			{
				if (visited[i][j]) continue;
				else
				{
					bin.push(make_pair(i, j));
					while (!bin.empty())
					{
						row = bin.top().first;
						col = bin.top().second;
						bin.pop();
						visited[row][col] = true;
						if (row - 1 >= 0 && grid[row - 1][col] == '1' && !visited[row - 1][col]) bin.push(make_pair(row - 1, col));
						if (row + 1 < m&&grid[row + 1][col] == '1' && !visited[row + 1][col]) bin.push(make_pair(row + 1, col));
						if (col - 1 >= 0 && grid[row][col - 1] == '1' && !visited[row][col - 1]) bin.push(make_pair(row, col - 1));
						if (col + 1 < n&&grid[row][col + 1] == '1' && !visited[row][col + 1]) bin.push(make_pair(row, col + 1));
					}
					++ans;
				}
			}
		}
	}
	return ans;
}