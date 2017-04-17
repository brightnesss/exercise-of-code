// leetcode No.119 Pascal's Triangle II

/*
 *	Given an index k, return the kth row of the Pascal's triangle.
 *	For example, given k = 0,
 *	Return [1],
 *	given k = 3,
 *	Return [1,3,3,1]. 
 */

vector<int> getRow(int rowIndex)
{
	vector<int> tmp = { 1 }, ans = { 1,1 };
	if (rowIndex == 0) return tmp;
	if (rowIndex == 1) return ans;
	for (int i = 2;i <= rowIndex;++i)
	{
		tmp.clear();
		for (int j = 0;j <= i;++j)
		{
			if (j == 0 || j == i) tmp.push_back(1);
			else tmp.push_back(ans[j - 1] + ans[j]);
		}
		ans = tmp;
	}
	return ans;
}