#include "includelib.h"

// leetcode No.463 Island Perimeter

// surroundWater将该区域外围扩展一圈，扩展的区域全是“水”
// linkCount计算每一个位置的四联通性，即若周围有“水”，则周长+1
// 遍历所有区域，对是陆地的区域计算其周长

void surroundWater(vector<vector<int>>& grid)
{
	int m = grid.size();
	int n = grid.begin()->size();
	for (vector<vector<int>>::iterator outIter = grid.begin();outIter != grid.end();++outIter)
	{
		outIter->push_back(0);
		outIter->insert(outIter->begin(), 0);
	}
	vector<int> TopandBottom(n + 2, 0);
	grid.insert(grid.begin(), TopandBottom);
	grid.push_back(TopandBottom);
}

int linkCount(vector<vector<int>>& grid,int i,int j)
{
	int ans(0);
	if (grid[i - 1][j] == 0) ++ans;
	if (grid[i + 1][j] == 0) ++ans;
	if (grid[i][j + 1] == 0) ++ans;
	if (grid[i][j - 1] == 0) ++ans;
	return ans;
}

int islandPerimeter(vector<vector<int>>& grid)
{
	surroundWater(grid);
	int m = grid.size();
	int n = grid.begin()->size();
	int ans(0);
	for (int i = 1;i != m;++i)
	{
		for (int j = 1;j != n;++j)
		{
			if (grid[i][j] == 1)
			{
				ans += linkCount(grid, i, j);
			}
			else continue;
		}
	}
	return ans;
}