/*
 *	130. Surrounded Regions
 *	Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
 *	A region is captured by flipping all 'O's into 'X's in that surrounded region.

 *	For example,
	X X X X
	X O O X
	X X O X
	X O X X

 *	After running your function, the board should be:
	X X X X
	X X X X
	X X X X
	X O X X
 *	应该是类似围棋,外围都可以看作O,即每一个区域的O必须上下左右都被X围住,才能算被围住
 */

/*
 *	广度优先搜索
 *	若搜索到边界上的点,就说明这些区域都没有被完全围住,不需要被填充
 *	否则,记录下所有搜索到的点,将这些的值变为'X'
 *	若用set<pair<int,int>>来记录已经访问过的点,则超时
 	若用vector<vector<bool>>来记录访问过的点,则超空间
 */
void solve(vector<vector<char>>& board)
{
	if (board.empty() || board[0].empty()) return;
	//set<pair<int, int>> visited;
	vector<pair<int, int>> to_change;	//记录下需要改变的点的坐标
	bool change(true);	//记录这个区域是否需要被改为X
	int m(board.size()), n(board[0].size());
	vector<vector<bool>> visited(m, vector<bool>(n, false));	//visited表示访问过的O
	for (int i = 0;i != m;++i)
	{
		for (int j = 0;j != n;++j)
		{
			if (board[i][j] == 'O')
			{
				if (visited[i][j]) continue;
				else
				{
					change = true;
					queue<pair<int, int>> q;
					pair<int, int> front;
					int row, col;
					to_change.clear();
					q.push(make_pair(i, j));
					while (!q.empty())
					{
						front = q.front();
						q.pop();
						to_change.push_back(front);	//记录下需要改变的点
						row = front.first;
						col = front.second;
						visited[row][col] = true;
						if (change)
						{
							if (row == 0 || row == m - 1 || col == 0 || col == n - 1) change = false;	//若访问的边界点,则这个区域不需要改变
						}
						//广度搜索
						if (row - 1 >= 0 && board[row - 1][col] == 'O'&&visited[row - 1][col] == false) q.push(make_pair(row - 1, col));
						if (row + 1 < m&&board[row + 1][col] == 'O'&&visited[row + 1][col] == false) q.push(make_pair(row + 1, col));
						if (col - 1 >= 0 && board[row][col - 1] == 'O'&&visited[row][col - 1] == false) q.push(make_pair(row, col - 1));
						if (col + 1 < n&&board[row][col + 1] == 'O'&&visited[row][col + 1] == false) q.push(make_pair(row, col + 1));
					}
					if (change)
					{
						//如果需要改变,才改为X
						for (int i = 0;i != to_change.size();++i)
						{
							board[to_change[i].first][to_change[i].second] = 'X';
						}
					}
				}
			}
		}
	}
}