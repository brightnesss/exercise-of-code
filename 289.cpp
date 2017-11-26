/*
 *	289. Game of Life
 *	According to the Wikipedia's article: "The Game of Life, also known simply as Life, 
 *	is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

 *	Given a board with m by n cells, each cell has an initial state live (1) or dead (0). 
 *	Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

 *	Any live cell with fewer than two live neighbors dies, as if caused by under-population.
 *	Any live cell with two or three live neighbors lives on to the next generation.
 *	Any live cell with more than three live neighbors dies, as if by over-population..
 *	Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
 *	Write a function to compute the next state (after one update) of the board given its current state.

 *	Follow up: 
 *	Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
 *	In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?
 */

int subGameOfLife(vector<vector<int>>& board,int i,int j, const int m, const int n)
{
	int count(0);
	if (i - 1 >= 0)
	{
		count += board[i - 1][j];
		if (j - 1 >= 0) count += board[i - 1][j - 1];
		if (j + 1 < n) count += board[i - 1][j + 1];
	}
	if (i + 1 < m)
	{
		count += board[i + 1][j];
		if (j - 1 >= 0) count += board[i + 1][j - 1];
		if (j + 1 < n) count += board[i + 1][j + 1];
	}
	{
		if (j - 1 >= 0) count += board[i][j - 1];
		if (j + 1 < n) count += board[i][j + 1];
	}
	return count;
}

void gameOfLife(vector<vector<int>>& board)
{
	vector<vector<int>> next(board);
	int m(board.size()), n(board[0].size()), count;
	for (int i = 0;i != m;++i)
	{
		for (int j = 0;j != n;++j)
		{
			count = subGameOfLife(board, i, j, m, n);
			if (board[i][j])
			{
				if (count < 2 || count>3) next[i][j] = 0;
			}
			else
			{
				if (count == 3) next[i][j] = 1;
			}
		}
	}
	swap(board, next);
}

/*
 *	in-place算法
 *	借用int的第二位来存放下一步数据
 */

int subGameOfLife(vector<vector<int>>& board,int i,int j, const int m, const int n)
{
	int count(0);
	if (i - 1 >= 0)
	{
		count += board[i - 1][j] & 1;
		if (j - 1 >= 0) count += board[i - 1][j - 1] & 1;
		if (j + 1 < n) count += board[i - 1][j + 1] & 1;
	}
	if (i + 1 < m)
	{
		count += board[i + 1][j] & 1;
		if (j - 1 >= 0) count += board[i + 1][j - 1] & 1;
		if (j + 1 < n) count += board[i + 1][j + 1] & 1;
	}
	{
		if (j - 1 >= 0) count += board[i][j - 1] & 1;
		if (j + 1 < n) count += board[i][j + 1] & 1;
	}
	return count;
}

void gameOfLife(vector<vector<int>>& board)
{
	int m(board.size()), n(board[0].size()), count;
	for (int i = 0;i != m;++i)
	{
		for (int j = 0;j != n;++j)
		{
			count = subGameOfLife(board, i, j, m, n);
			if (board[i][j] & 1)
			{
				if (count == 2 || count == 3) board[i][j] |= 2;
			}
			else
			{
				if (count == 3) board[i][j] |= 2;
			}
		}
	}
	for (int i = 0;i != m;++i)
	{
		for (int j = 0;j != n;++j)
		{
			board[i][j] >>= 1;
		}
	}
}