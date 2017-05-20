//leetcode No.419 Battleships in a Board 

/*
 *	Given an 2D board, count how many battleships are in it. The battleships are represented with 'X's, empty slots are represented with '.'s. You may assume the following rules: 
 * You receive a valid board, made of only battleships or empty slots.
 *	Battleships can only be placed horizontally or vertically. In other words, they can only be made of the shape 1xN (1 row, N columns) or Nx1 (N rows, 1 column), where N can be of any size.
 *	At least one horizontal or vertical cell separates between two battleships - there are no adjacent battleships.

 *	Example:
 *	X..X
 *	...X
 *	...X
 *	In the above board there are 2 battleships. 
 
 *	Invalid Example:
 *	...X
 *	XXXX
 *	...X
 *	This is an invalid board that you will not receive - as battleships will always have a cell separating between them. 

 *	Follow up:
 *	Could you do it in one-pass, using only O(1) extra memory and without modifying the value of the board?
 */

//每两个模式之间一定有分隔
//从左向右扫描，从上到下扫描
//每找到一个'X',就计数+1,除非这个位置的上面或左边也是'X',此时这个模式已经被记录过了
int countBattleships(vector<vector<char>>& board)
{
	int count(0);
	int m = board.size(), n = board[0].size();
	for (int i = 0;i != m;++i)
	{
		for (int j = 0;j != n;++j)
		{
			if (board[i][j] == '.') continue;
			else
			{
				if (i == 0 && j == 0) ++count;
				else if (i == 0)
				{
					if (board[i][j - 1] == '.') ++count;
					else continue;
				}
				else if (j == 0)
				{
					if (board[i - 1][j] == '.') ++count;
					else continue;
				}
				else
				{
					if (board[i - 1][j] == '.'&&board[i][j - 1] == '.') ++count;
					else continue;
				}
			}
		}
	}
	return count;
}