//leetcode No.529 Minesweeper 

/*
 *	Let's play the minesweeper game (Wikipedia, online game)! 
 *	You are given a 2D char matrix representing the game board. 'M' represents an unrevealed mine, 'E' represents an unrevealed empty square, 'B' represents a revealed blank square that has no adjacent (above, below, left, right, and all 4 diagonals) mines, digit ('1' to '8') represents how many mines are adjacent to this revealed square, and finally 'X' represents a revealed mine.
 *	Now given the next click position (row and column indices) among all the unrevealed squares ('M' or 'E'), return the board after revealing this position according to the following rules:

 *	If a mine ('M') is revealed, then the game is over - change it to 'X'.
 *	If an empty square ('E') with no adjacent mines is revealed, then change it to revealed blank ('B') and all of its adjacent unrevealed squares should be revealed recursively.
 *	If an empty square ('E') with at least one adjacent mine is revealed, then change it to a digit ('1' to '8') representing the number of adjacent mines.
 *	Return the board when no more squares will be revealed.
 */

int isMine(vector<vector<char>>& board, const int i, const int j)
{
	//判断是否是雷
	if (i == -1 || i == board.size() || j == -1 || j == board[0].size()) return 0;
	if (board[i][j] == 'M') return 1;
	else return 0;
}

bool isVisted(vector<vector<char>>& board, const int i, const int j)
{
	//判断有没有探开这一格
	if (i == -1 || i == board.size() || j == -1 || j == board[0].size()) return false;
	if (board[i][j] == 'E') return true;
	else return false;
}

int countMine(vector<vector<char>>& board,const int &i,const int &j)
{
	//计算周围的雷数
	int count(0);
	int m = board.size();
	int n = board[0].size();
	if (i == 0)
	{
		if (j == 0) count = isMine(board, i, j + 1) + isMine(board, i + 1, j) + isMine(board, i + 1, j + 1);
		else if (j == n - 1) count = isMine(board, i, j - 1) + isMine(board, i + 1, j - 1) + isMine(board, i + 1, j);
		else count = isMine(board, i, j - 1) + isMine(board, i + 1, j - 1) + isMine(board, i + 1, j) + isMine(board, i + 1, j + 1) + isMine(board, i, j + 1);
	}
	else if (i == m - 1)
	{
		if (j == 0) count = isMine(board, i, j + 1) + isMine(board, i - 1, j) + isMine(board, i - 1, j + 1);
		else if (j == n - 1) count = isMine(board, i, j - 1) + isMine(board, i - 1, j - 1) + isMine(board, i - 1, j);
		else count = isMine(board, i, j - 1) + isMine(board, i - 1, j - 1) + isMine(board, i - 1, j) + isMine(board, i - 1, j + 1) + isMine(board, i, j + 1);
	}
	else
	{
		if (j == 0) count = isMine(board, i, j + 1) + isMine(board, i + 1, j) + isMine(board, i + 1, j + 1) + isMine(board, i - 1, j) + isMine(board, i - 1, j + 1);
		else if (j == n - 1) count = isMine(board, i, j - 1) + isMine(board, i - 1, j - 1) + isMine(board, i - 1, j) + isMine(board, i + 1, j - 1) + isMine(board, i + 1, j);
		else count = isMine(board, i, j - 1) + isMine(board, i - 1, j - 1) + isMine(board, i - 1, j) + isMine(board, i - 1, j + 1) + isMine(board, i, j + 1) + isMine(board, i + 1, j - 1) + isMine(board, i + 1, j) + isMine(board, i + 1, j + 1);
	}

	return count;
}

vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click)
{
	int i(click[0]), j(click[1]);
	if (isMine(board, i, j))
	{
		//如果踩中雷，结束
		board[i][j] = 'X';
		return board;
	}
	queue<pair<int, int>> graph; 	//采用广度优先搜索
	pair<int, int> point;
	graph.push(make_pair(i, j));
	while (!graph.empty())
	{
		point = graph.front();
		graph.pop();
		if (!isVisted(board, point.first, point.second)) continue; 	//有可能会重复入队
		int numMine = countMine(board, point.first, point.second); 
		if (numMine == 0)
		{
			//如果这一格的周围没有雷，那就周围全都要继续探开
			i = point.first;
			j = point.second;
			board[point.first][point.second] = 'B';
			if (isVisted(board, i - 1, j - 1)) graph.push(make_pair(i - 1, j - 1));
			if (isVisted(board, i - 1, j)) graph.push(make_pair(i - 1, j));
			if (isVisted(board, i - 1, j + 1)) graph.push(make_pair(i - 1, j + 1));
			if (isVisted(board, i, j - 1)) graph.push(make_pair(i, j - 1));
			if (isVisted(board, i, j + 1)) graph.push(make_pair(i, j + 1));
			if (isVisted(board, i + 1, j - 1)) graph.push(make_pair(i + 1, j - 1));
			if (isVisted(board, i + 1, j)) graph.push(make_pair(i + 1, j));
			if (isVisted(board, i + 1, j + 1)) graph.push(make_pair(i + 1, j + 1));
		}
		else
		{
			//如果周围有雷，就标记上雷的数目
			board[point.first][point.second] = '0' + numMine;
		}
	}
	return board;
}