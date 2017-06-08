//leetocde No.554 Brick Wall 

/*
 *	There is a brick wall in front of you. The wall is rectangular and has several rows of bricks. The bricks have the same height but different width. You want to draw a vertical line from the top to the bottom and cross the least bricks. 
 *	The brick wall is represented by a list of rows. Each row is a list of integers representing the width of each brick in this row from left to right. 
 *	If your line go through the edge of a brick, then the brick is not considered as crossed. You need to find out how to draw the line to cross the least bricks and return the number of crossed bricks. 
 *	You cannot draw a line just along one of the two vertical edges of the wall, in which case the line will obviously cross no bricks. 
 */


//用一个map记录下每一行墙的可能分隔的情况
//最后找最大的可能分隔的情况
//则答案要求的最少穿过几层墙就是所有的墙数-最大公共分隔
int leastBricks(vector<vector<int>>& wall)
{
	int len = wall.size();
	int walllen = accumulate(wall[0].begin(), wall[0].end(), 0);
	unordered_map<int, int> bin;
	for (int i = 0;i != wall.size();++i)
	{
		int tmp(0);
		vector<int> row = wall[i];
		for (int j = 0;j != row.size();++j)
		{
			tmp += row[j];
			if (tmp == walllen) break;
			else ++bin[tmp];
		}
	}
	int ans(0);
	for (unordered_map<int, int>::iterator it = bin.begin();it != bin.end();++it) if (it->second > ans) ans = it->second;
	return len - ans;
}