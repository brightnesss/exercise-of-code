/*
 *	85. Maximal Rectangle
 *	Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
 *	For example, given the following matrix:

	1 0 1 0 0
	1 0 1 1 1
	1 1 1 1 1
	1 0 0 1 0
 *	Return 6.
 */


/*
 *	利用84题Largest Rectangle in Histogram的结果
 *	将matrix每一行看作一个横截面,将该行以上的部分投影到该行,构成了heights数组,输入84题的结果中,进行计算
 *	这样一行一行的计算下来,可以得到整个matrix的结果
 */
int maximalRectangle(vector<vector<char>>& matrix)
{
	if (matrix.empty() || matrix[0].empty()) return 0;
	int m(matrix.size()), n(matrix[0].size());
	vector<int> heights(n, 0);
	int area(0);
	for (int i = 0;i != m;++i)
	{
		for (int j = 0;j != n;++j)
		{
			if (matrix[i][j] == '1') heights[j] += 1;	//如果该行j列为'1',则该列高度为+1
			else heights[j] = 0;	//若该行j列为'0',则以上的高度都为0(即不能构成长方形)
		}
		area = max(area, largestRectangleArea_v2(heights));
	}
	return area;
}

int largestRectangleArea_v2(vector<int>& heights)
{
	stack<int> bin;
	int count(1), area(0), tmp;
	heights.push_back(0);
	for (int i = 0;i != heights.size();++i)
	{
		tmp = heights[i];
		if (bin.empty() || tmp >= bin.top()) bin.push(tmp);
		else
		{
			while (!bin.empty() && bin.top() > tmp)
			{
				area = max(area, bin.top()*count);
				bin.pop();
				++count;
			}
			while (count)
			{
				bin.push(tmp);
				--count;
			}
			count = 1;
		}
	}
	heights.pop_back();
	return area;
}