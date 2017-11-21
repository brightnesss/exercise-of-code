/*
 *	Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

 *	For example,
 *	Given the following matrix:
	[
 	 [ 1, 2, 3 ],
 	 [ 4, 5, 6 ],
 	 [ 7, 8, 9 ]
	]

 *	You should return [1,2,3,6,9,8,7,4,5].
 */

vector<int> spiralOrder(vector<vector<int>>& matrix)
{
	int m(matrix.size());
	if (m == 0) return vector<int>{};
	int n(matrix[0].size());
	const int num(m*n);
	//lcol是左边的边界,rcol是右边边界,trow是上面边界,brow是下面的边界,每到达一次边界,这些边界的值都要向内收缩
	int lcol(0), rcol(n - 1), trow(0), brow(m - 1);
	int i(0), j(0), count(0);
	vector<int> ans;
	while (count < num)
	{
		i = trow, j = lcol;
		++trow;	//上边界向下收缩
		while (j <= rcol)
		{
			ans.push_back(matrix[i][j]);
			++j;
			++count;
		}
		if (count == num) break;
		i += 1;
		j -= 1;
		--rcol;	//有边界向左收缩

		while (i <= brow)
		{
			ans.push_back(matrix[i][j]);
			++i;
			++count;
		}
		if (count == num) break;
		i -= 1;
		j -= 1;
		--brow;	//下边界向上收缩

		while (j >= lcol)
		{
			ans.push_back(matrix[i][j]);
			--j;
			++count;
		}
		if (count == num) break;
		j += 1;
		i -= 1;
		++lcol;	//左边界向右收缩

		while (i >= trow)
		{
			ans.push_back(matrix[i][j]);
			--i;
			++count;
		}
		if (count == num) break;
		i += 1;
		j += 1;
	}
	return ans;
}