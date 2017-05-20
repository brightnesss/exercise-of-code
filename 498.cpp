//leetcode No.498 Diagonal Traverse 

/*
 *	Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order.
 */

vector<int> findDiagonalOrder(vector<vector<int>>& matrix)
{
	vector<int> ans;
	if (matrix.empty()) return ans;
	int m(matrix.size()), n(matrix[0].size());
	int i(0), j(0);
	while (ans.size() != m*n)
	{
		while (i != -1 && j != n)
		{
			//从左下往右上
			ans.push_back(matrix[i][j]);
			--i;
			++j;
		}
		if (j == n)
		{
			//过了次对角线的情况
			j = n - 1;
			i += 2;
		}
		if (i == -1) i = 0;

		while (i != m && j != -1)
		{
			//从右上往左下
			ans.push_back(matrix[i][j]);
			++i;
			--j;
		}
		if (i == m)
		{
			//过了次对角线的情况
			i = m - 1;
			j += 2;
		}
		if (j == -1) j = 0;
	}
	return ans;
}