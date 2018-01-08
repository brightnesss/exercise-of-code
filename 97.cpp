/*
 *	97. Interleaving String
 *	Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

 *	For example,
 *	Given:
 *	s1 = "aabcc",
 *	s2 = "dbbca",
 *	When s3 = "aadbbcbcac", return true.
 *	When s3 = "aadbbbaccc", return false.
 */

/*
 *	动态规划
 *	假设我们构建一个棋盘,s1代表行,s2代表列,每次只能向右或者向下走,最后看s3这条路径能不能够从左上到达右下(每一次转折都代表交替一次)
 *	首先,若s1的长度和s2的长度之和不等于s3的长度,则肯定不行,返回false
 *	设dp[i][j]，表示s1[0,i-1]和s2[0,j-1]交替组成s3[0, i+j-1]
 *	如果s1[i-1]等于s3[i+j-1]，则dp[i][j]=dp[i-1][j]； 
 *	如果s2[j-1]等于s3[i+j-1]，则dp[i][j]=dp[i][j-1]。
 */

bool isInterleave(string s1, string s2, string s3)
{
	if (s1.size() + s2.size() != s3.size()) return false;
	int len1(s1.size()), len2(s2.size());
	vector<vector<bool>> bin(len1 + 1, vector<bool>(len2 + 1, false));
	bin[0][0] = true;
	for (int i = 1;i != len1 + 1;++i) bin[i][0] = bin[i - 1][0] && s1[i - 1] == s3[i - 1];
	for (int j = 1;j != len2 + 1;++j) bin[0][j] = bin[0][j - 1] && s2[j - 1] == s3[j - 1];
	for (int i = 1;i != len1 + 1;++i)
	{
		for (int j = 1;j != len2 + 1;++j)
		{
			bin[i][j] = (bin[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (bin[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
		}
	}
	return bin[len1][len2];
}