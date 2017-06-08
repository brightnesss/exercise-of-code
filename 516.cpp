//leetcode No.516 Longest Palindromic Subsequence 

/*
 *	Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000. 
 *	Example 1:
 *	Input: 
 *	"bbbab"
 *	Output: 
 *	4
 *	One possible longest palindromic subsequence is "bbbb". 

 *	Example 2:
 *	Input: 
 *	"cbbd"
 *	Output: 
 *	2
 */


/*
 *使用动态规划
 *	设立一个len行len列的bin数组
 *	bin[i][j]表示字符串i~j下标所构成的子串中最长回文子串的长度
 *	最后我们需要返回的是bin[0][len-1]的值
 *	初始情况为bin[i][i] = 1
 *	bin数组更新：如果当前i和j所指元素相等，说明能够加到i~j的回文子串的长度中，所以更新bin[i][j] = bin[i+1][j-1] + 2;
 *	如果当前元素不相等，那么说明这两个i,j所指元素对回文串无贡献，则bin[i][j]就是从bin[i+1][j]和dp[i][j-1]中选取较大的一个值即可
 */

int longestPalindromeSubseq(string s)
{
	if (s.empty()) return 0;
	int len = s.length();
	vector<vector<int>> bin(len, vector<int>(len));
	for (int i = 0;i != len;++i) bin[i][i] = 1;
	for (int i = len - 1;i >= 0;--i)
	{
		for (int j = i + 1;j < len;++j)
		{
			if (s[i] == s[j]) bin[i][j] = bin[i + 1][j - 1] + 2;
			else bin[i][j] = max(bin[i + 1][j], bin[i][j - 1]);
		}
	}
	return bin[0][len - 1];
}