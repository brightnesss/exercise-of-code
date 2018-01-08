/*
 *	36. Valid Sudoku
 *	Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
 *	The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
 *	A partially filled sudoku which is valid.

 *	Note:
	A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

 *	本题的意思就是给你一个数独矩阵,判断这个矩阵当下是否是合法的,而不是判断这个矩阵能不能填充成为一个合法的数独
 */

/*
 *	数独肯定是9*9的,包含9个小方格
 *	所以用row,col,grid来分别表示这9行,9列,9个小方格的情况
 *	每遍历一个board的点,都搜索行,列,小方格内是否存在重复的情况,若存在,则返回false,否则继续
 */

bool isValidSudoku(vector<vector<char>>& board)
{
	if (board.empty() || board[0].empty()) return false;
	int m(board.size()), n(board[0].size());
	if (m != 9 || n != 9) return false;
	vector<set<char>> row(9), col(9), grid(9);
	int gridindex;
	for (int i = 0;i != m;++i)
	{
		for (int j = 0;j != n;++j)
		{
			if (board[i][j] != '.')
			{
				if (row[i].find(board[i][j]) == row[i].end()) row[i].insert(board[i][j]);
				else return false;
				if (col[j].find(board[i][j]) == col[j].end()) col[j].insert(board[i][j]);
				else return false;
				gridindex = (i / 3) * 3 + (j / 3);
				if (grid[gridindex].find(board[i][j]) == grid[gridindex].end()) grid[gridindex].insert(board[i][j]);
				else return false;
			}
		}
	}
	return true;
}