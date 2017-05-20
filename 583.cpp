//leetcode No.583 Delete Operation for Two Strings 

/*
 *	Given two words word1 and word2, find the minimum number of steps required to make word1 and word2 the same, where in each step you can delete one character in either string. 

 *	Example:
 *	Input: "sea", "eat"
 *	Output: 2
 *	Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
 */

/*
 *	求公共最长子序列,动态规划,建立一个m,n的矩阵
 *	该矩阵的(i,j)元素表示截至到word1的第i位与word2的第j位,子序列的数目
 *	则最长的子序列长度为bin[m-1][n-1]
 *	该题的答案为(m-bin[m-1][n-1])+(n-bin[m-1][n-1])
 */

int minDistance(string word1, string word2)
{
	int m(word1.size()), n(word2.size());
	if (m == 0 || n == 0) return max(m, n);
	vector<vector<int>> bin(m, vector<int>(n)), flag(m, vector<int>(n));
	for (int i = 0;i != m;++i)
	{
		for (int j = 0;j != n;++j)
		{
			if (i == 0 && j == 0) bin[i][j] = word1[i] == word2[j] ? 1 : 0;
			else if (i == 0) bin[i][j] = word1[i] == word2[j] ? 1 : bin[i][j - 1];
			else if (j == 0) bin[i][j] = word1[i] == word2[j] ? 1 : bin[i - 1][j];
			else bin[i][j] = word1[i] == word2[j] ? bin[i - 1][j - 1] + 1 : max(bin[i - 1][j], bin[i][j - 1]);
		}
	}
	return m + n - (bin[m - 1][n - 1] << 1);
}

/*
 *	version 2:
 *	如果还需要输出最长的子序列
 *	通过flag这个数组来记录
 *	如果word1[i]==word[j],则表示斜下取,设标志位为1
 *	如果bin[i-1][j]>bin[i][j-1],表示word1取下一位,即bin向下取,令标志位为2
 *	否则,表示word2取下一位,即bin向右取,令标志位为3
 */

string minDistance(string word1, string word2)
{
	int m(word1.size()), n(word2.size());
	if (m == 0 || n == 0) string();
	vector<vector<int>> bin(m, vector<int>(n)), flag(m, vector<int>(n));
	for (int i = 0;i != m;++i)
	{
		for (int j = 0;j != n;++j)
		{
			if (i == 0 && j == 0)
			{
				//bin[0][0]这里特殊,若word1[0]==word2[0],好说,flag[0][0]=1,其他情况都令flag为3,即向右
				if (word1[i] == word2[j])
				{
					bin[i][j] = 1;
					flag[i][j] = 1; //向斜下
				}
				else
				{
					bin[i][j] = 0;
					flag[i][j] = 3; //向水平右
				}
			}
			else if (i == 0)
			{
				if (word1[i] == word2[j])
				{
					bin[i][j] = 1;
					flag[i][j] = 1;
				}
				else
				{
					bin[i][j] = bin[i][j - 1];
					flag[i][j] = 3; //向右
				}
			}
			else if (j == 0)
			{
				if (word1[i] == word2[j])
				{
					bin[i][j] = 1;
					flag[i][j] = 1;
				}
				else
				{
					bin[i][j] = bin[i-1][j];
					flag[i][j] = 2; //向垂直下
				}
			}
			else
			{
				if (word1[i] == word2[j])
				{
					bin[i][j] = bin[i - 1][j - 1] + 1;
					flag[i][j] = 1;
				}
				else if (bin[i - 1][j] > bin[i][j - 1])
				{
					bin[i][j] = bin[i - 1][j];
					flag[i][j] = 2;
				}
				else
				{
					bin[i][j] = bin[i][j - 1];
					flag[i][j] = 3;
				}
			}
		}
	}
	string ans;
	int i(0), j(0);
	while (i != m && j != n)
	{
		if (flag[i][j] == 1)
		{
			//如果向斜下了,说明这一位相同,是子串的一部分
			ans += word1[i];
			++i;
			++j;
		}
		//否则都继续找
		else if (flag[i][j] == 2)
		{
			++i;
		}
		else ++j;
	}
	return ans;
}