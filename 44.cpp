/*
 *	44. Wildcard Matching
 *	Implement wildcard pattern matching with support for '?' and '*'.

 	'?' Matches any single character.
 	'*' Matches any sequence of characters (including the empty sequence).

 *	The matching should cover the entire input string (not partial).
 *	The function prototype should be:
 *	bool isMatch(const char *s, const char *p)

 *	Some examples:
 *	isMatch("aa","a") → false
 *	isMatch("aa","aa") → true
 *	isMatch("aaa","aa") → false
 *	isMatch("aa", "*") → true
 *	isMatch("aa", "a*") → true
 *	isMatch("ab", "?*") → true
 *	isMatch("aab", "c*a*b") → false
 */

/*
 *	动态规划
 *	若p[j-1]=='*':
 *		1)若bin[i-1][j-1]==true,即s和p之前的都相等,则这个'*'可以匹配s之后的所有字符了, 即对于任意new_i>=i,bin[new_i][j]=true
 *		2)若bin[i-1][j-1]!=true,但是bin[i][j-1]==true,即不需要这个'*',bin[i][j]=true,此时'*'匹配empty sequence
 *	若p[j-1]!='*'
 		则只能bin[i-1][j-1]==true且s[i-1]==p[j-1],才能使bin[i][j]=true
 */
bool isMatch_44(string s, string p)
{
	int m(s.size() + 1), n(p.size() + 1);
	vector<vector<bool>> bin(m, vector<bool>(n, false));
	bin[0][0] = true;
	for (int j = 1;j != n;++j)
	{
		if (p[j - 1] == '*'&&bin[0][j - 1]) bin[0][j] = true;
	}

	for (int j = 1;j != n;++j)
	{
		for (int i = 1;i != m;++i)
		{
			if (p[j - 1] == '*')
			{
				if (bin[i - 1][j - 1])
				{
					for (int new_i = i;new_i != m;++new_i) bin[new_i][j] = true;
					break;
				}
				else if (bin[i][j - 1]) bin[i][j] = true;
			}
			else if (p[j - 1] == '?')
			{
				if (bin[i - 1][j - 1]) bin[i][j] = true;
			}
			else
			{
				if (bin[i - 1][j - 1] && s[i - 1] == p[j - 1]) bin[i][j] = true;
			}
		}
	}
	return bin[m - 1][n - 1];
}

