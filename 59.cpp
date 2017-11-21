//leetcode No.59 Spiral Matrix II

/*
 *	Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

 *	For example,
 *	Given n = 3,

 *	You should return the following matrix:
	[
 	 [ 1, 2, 3 ],
 	 [ 8, 9, 4 ],
  	 [ 7, 6, 5 ]
	]
 */

vector<vector<int>> generateMatrix(int n)
{
	vector<vector<int>> ans(n, vector<int>(n, -1));
	int count(0), row(0), col(0);
	while (count < n*n)
	{
		while (count < n*n && col < n && ans[row][col] == -1)
		{
			ans[row][col] = ++count;
			++col;
		}
		col -= 1;
		row += 1;
		while (count < n*n && row < n && ans[row][col] == -1)
		{
			ans[row][col] = ++count;
			++row;
		}
		row -= 1;
		col -= 1;
		while (count<n*n && col>-1 && ans[row][col] == -1)
		{
			ans[row][col] = ++count;
			--col;
		}
		col += 1;
		row -= 1;
		while (count<n*n && row>-1 && ans[row][col] == -1)
		{
			ans[row][col] = ++count;
			--row;
		}
		col += 1;
		row += 1;
	}
	return ans;
}


//和54相似
vector<vector<int>> generateMatrix(int n)
{
	vector<vector<int>> ans( n,vector<int>(n, 0) );
	int num(1), count(0);
	int lcol(0), rcol(n - 1), trow(1), brow(n - 1);
	int i(0), j(0);
	while (true)
	{
		if (num <= n*n)
		{
			while (j <= rcol)
			{
				ans[i][j] = num;
				++num;
				++j;
			}
			j -= 1;
			i += 1;
			rcol -= 1;
		}
		else break;

		if (num <= n*n)
		{
			while (i <= brow)
			{
				ans[i][j] = num;
				++num;
				++i;
			}
			i -= 1;
			j -= 1;
			brow -= 1;
		}
		else break;

		if (num <= n*n)
		{
			while (j >= lcol)
			{
				ans[i][j] = num;
				++num;
				--j;
			}
			j += 1;
			i -= 1;
			lcol += 1;
		}
		else break;

		if (num <= n*n)
		{
			while (i >= trow)
			{
				ans[i][j] = num;
				++num;
				--i;
			}
			i += 1;
			j += 1;
			trow += 1;
		}
		else break;
	}
	return ans;
}