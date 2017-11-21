/*
 *	118. Pascal's Triangle
 *	Given numRows, generate the first numRows of Pascal's triangle.
 *	For example, given numRows = 5,
 *	Return

	[
    	 [1],
    	[1,1],
	   [1,2,1],
  	  [1,3,3,1],
 	 [1,4,6,4,1]
	]
 */

vector<vector<int>> generate(int numRows)
{
	if (numRows == 0) return vector<vector<int>>{};
	if (numRows == 1) return vector<vector<int>>{vector<int>{1}};
	if (numRows == 2) return vector<vector<int>>{vector<int>{1}, vector<int>{1, 1}};
	vector<vector<int>> ans{ vector<int>{1}, vector<int>{1, 1} };
	vector<int> tmp{ 1,1 };
	for (int i = 3;i <= numRows;++i)
	{
		for (int j = 1;j != tmp.size();++j)
		{
			tmp[j-1] = tmp[j] + tmp[j - 1];
		}
		tmp.insert(tmp.begin(), 1);
		ans.push_back(tmp);
	}
	return ans;
}