/*
 *	79. Word Search
 *	Given a 2D board and a word, find if the word exists in the grid.
 *	The word can be constructed from letters of sequentially adjacent cell, 
 *	where "adjacent" cells are those horizontally or vertically neighboring. 
 *	The same letter cell may not be used more than once.

 *	For example,
 *	Given board =

	[
  	 ['A','B','C','E'],
  	 ['S','F','C','S'],
  	 ['A','D','E','E']
	]

 *	word = "ABCCED", -> returns true,
 *	word = "SEE", -> returns true,
 *	word = "ABCB", -> returns false.
 */

void subexist(vector<vector<char>>& board, string& word, int index, bool& isfind, int i,int j, int& m, int& n,vector<pair<int,int>> bin)
{
	if (index == word.size())
	{
		isfind = true;
		return;
	}
	if (isfind) return;
	if (i - 1 >= 0 && board[i - 1][j] == word[index])
	{
		if (find(bin.begin(), bin.end(), make_pair(i - 1, j)) == bin.end())
		{
			bin.push_back(make_pair(i - 1, j));
			subexist(board, word, index + 1, isfind, i - 1, j, m, n, bin);
			bin.pop_back();
		}
	}
	if (i + 1 < m && board[i + 1][j] == word[index])
	{
		if (find(bin.begin(), bin.end(), make_pair(i + 1, j)) == bin.end())
		{
			bin.push_back(make_pair(i + 1, j));
			subexist(board, word, index + 1, isfind, i + 1, j, m, n, bin);
			bin.pop_back();
		}
	}
	if (j - 1 >= 0 && board[i][j - 1] == word[index])
	{
		if (find(bin.begin(), bin.end(), make_pair(i, j - 1)) == bin.end())
		{
			bin.push_back(make_pair(i, j - 1));
			subexist(board, word, index + 1, isfind, i, j - 1, m, n, bin);
			bin.pop_back();
		}
	}
	if (j + 1 < n && board[i][j + 1] == word[index])
	{
		if (find(bin.begin(), bin.end(), make_pair(i, j + 1)) == bin.end())
		{
			bin.push_back(make_pair(i, j + 1));
			subexist(board, word, index + 1, isfind, i, j + 1, m, n, bin);
			bin.pop_back();
		}
	}
}

bool exist(vector<vector<char>>& board, string word)
{
	int index(0);
	int m(board.size()), n(board[0].size());
	bool isfind(false);
	vector<pair<int, int>> bin;
	for (int i = 0;i != m;++i)
	{
		for (int j = 0;j != n;++j)
		{
			if (board[i][j] == word[0])
			{
				bin.push_back(make_pair(i, j));
				subexist(board, word, index + 1, isfind, i, j, m, n, bin);
				bin.pop_back();
			}
		}
	}
	return isfind;
}