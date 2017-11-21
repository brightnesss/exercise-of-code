/*
 *	120. Triangle
 *	Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
 *	For example, given the following triangle
	[
    	 [2],
    	[3,4],
       [6,5,7],
  	  [4,1,8,3]
	]
 *	The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

 *	Note:
 *	Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
 */

//回溯法,超时
//rowIndex是记录当前遍历到triangle的第几层,colIndex是上一层中的第几个元素,total是截至到上一层的和,totalAns是整个问题的解,是目前已知的最优值,用来对回溯进行剪枝
int subMiniMumTotal(vector<vector<int>>& triangle, int rowIndex, int colIndex, int total, int totalAns)
{
	if (rowIndex >= triangle.size()) return total;
	int ans(INT_MAX);
	for (int i = colIndex;i <= colIndex + 1;++i)
	{
		if (i == -1) continue;
		if (i == triangle[rowIndex].size()) continue;
		if (triangle[rowIndex][i] + total >= totalAns) return totalAns;
		ans = min(ans, subMiniMumTotal(triangle, rowIndex + 1, i, total + triangle[rowIndex][i], ans));
	}
	return ans;
}

int minimumTotal(vector<vector<int>>& triangle)
{
	if (triangle.empty()) return 0;
	int ans(INT_MAX);
	for (int i = 0;i != triangle[0].size();++i)
	{
		ans = min(ans, subMiniMumTotal(triangle, 1, i, triangle[0][i], ans));
	}
	return ans;
}

//动态规划,空间复杂度O(n)
//bin相当于存第i层以下的所有情况
int minimumTotal(vector<vector<int>>& triangle)
{
    vector<int> bin=*triangle.rbegin();	//以triangle的最后一层为初始化值
    for (int i=triangle.size()-2;i>=0;--i)
    {
        for (int j=0;j!=triangle[i].size();++j)
        {
            bin[j]=triangle[i][j]+min(bin[j],bin[j+1]);		//每次遍历,取紧邻triangle[i][j]的两个下层值
        }
    }
    return bin[0];
}