/*
 *	73. Set Matrix Zeroes
 *	Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
 */

//这不是原地操作,空间复杂度O(max(m,n))
void setZeroes(vector<vector<int>>& matrix)
{
	set<int> cols, rows;
	int m(matrix.size()), n(matrix[0].size());
	for (int i = 0;i != m;++i)
	{
		for (int j = 0;j != n;++j)
		{
			if (matrix[i][j] == 0)
			{
				cols.insert(j);
				rows.insert(i);
			}
		}
	}
	for (set<int>::iterator rit = rows.begin();rit != rows.end();++rit)
	{
		const int r = *rit;
		for (int j = 0;j != n;++j) matrix[r][j] = 0;
	}
	for (set<int>::iterator cit = cols.begin();cit != cols.end();++cit)
	{
		const int c = *cit;
		for (int i = 0;i != m;++i) matrix[i][c] = 0;
	}
}

/*
 *	原地操作,空间复杂度O(1)
 *	使用第一行和第一列来记录是否有0的信息
 *	但这样matrix[0][0]就出现了复杂性,不知道是第一行中有0,还是第一列中有0,还是本身是0,需要分开讨论
 *	首先只用matrix[0][0]点记录第一列,这样就屏蔽了第一行有0的情况
 *	其次,使用is_row0来记录第一行是否有0,来避免本身是0的情况
 */
void setZeroes_v2(vector<vector<int>>& matrix)
{
	int m(matrix.size()), n(matrix[0].size());
	bool is_row0(false);
	for (int j = 0;j != n;++j)
	{
		if (matrix[0][j] == 0) is_row0 = true;
	}
	for (int i = 1;i != m;++i)
	{
		for (int j = 0;j != n;++j)
		{
			if (matrix[i][j] == 0)
			{
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}
	}

	for (int i = 1;i != m;++i)
	{
		if (matrix[i][0] == 0)
		{
			for (int j = 1;j != n;++j) matrix[i][j] = 0;
		}
	}
	for (int j = 1;j != n;++j)
	{
		if (matrix[0][j] == 0)
		{
			for (int i = 1;i != m;++i) matrix[i][j] = 0;
		}
	}
	if (matrix[0][0] == 0)
	{
		for (int j = 0;j != n;++j) matrix[0][j] = 0;
	}
	if (is_row0)
	{
		for (int j = 0;j != n;++j) matrix[0][j] = 0;
	}
}