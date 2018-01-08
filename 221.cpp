/*
 *	221. Maximal Square
 *	Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

 *	For example, given the following matrix:

	1 0 1 0 0
	1 0 1 1 1
	1 1 1 1 1
	1 0 0 1 0
 	Return 4.
 */

/*
 *	和85题相似,只不过一个是正方形一个是长方形
 *	所以在计算面积的时候有一点不同,只在子函数中不同
 */
int subMaximalSquare(vector<int> &layer)
{
	if (layer.empty()) return 0;
	layer.push_back(0);
	stack<int> bin;
	int ans(0), num, stride;
	for (int i = 0;i != layer.size();++i)
	{
		if (bin.empty() || bin.top() <= layer[i]) bin.push(layer[i]);
		else
		{
			int count(1);
			num = layer[i];
			while (!bin.empty()&&bin.top() > layer[i])
			{
				stride = min(count, bin.top());	//因为是正方形,所以面积是长和高中的小者,仅仅这里不同
				ans = max(ans, stride*stride);
				bin.pop();
				++count;
			}
			while (count--) bin.push(layer[i]);
		}
	}
	layer.pop_back();
	return ans;
}

int maximalSquare(vector<vector<char>>& matrix)
{
	if (matrix.empty() || matrix[0].empty()) return 0;
	int m(matrix.size()), n(matrix[0].size());
	vector<int> height(n, 0);
	int ans(0);
	for (int i = 0;i != m;++i)
	{
		for (int j = 0;j != n;++j)
		{
			if (matrix[i][j] == '0') height[j] = 0;
			else height[j] += 1;
		}
		ans = max(ans, subMaximalSquare(height));
	}
	return ans;
}