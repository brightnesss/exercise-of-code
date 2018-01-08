/*
 *	5. Longest Palindromic Substring
 *	Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

 *	Example:
 *	Input: "babad"
 *	Output: "bab"
 *	Note: "aba" is also a valid answer.

 *	Example:
 *	Input: "cbbd"
 *	Output: "bb"
 */

/*
 *	动态规划,时间复杂度O(n2),空间复杂度O(n2)
 *	设bin[i,j]来表示substr(s[i]...s[j])是否为回文
 *	初始条件为:
 		1)bin[i][i]=true
 		2)bin[i][i+1]=true if s[i]==s[i+1]
 *	状态更新为:
 		bin[i][j]=true if bin[i+1][j-1]==true&&s[i]==s[j]	bin[i+1][j-1]是向内缩了两个字符的子串
 */
string longestPalindrome(string s)
{
	if (s.empty()) return "";
	int len(s.size());
	vector<vector<bool>> bin(len, vector<bool>(len, 0));
	int start, maxLen;
	for (int i = 0;i != len;++i)
	{
		bin[i][i] = true;	//初始条件1
		if (i != len - 1)
		{
			if (s[i] == s[i + 1])
			{
				bin[i][i + 1] = true;	//初始条件2
				start = i;
				maxLen = 2;
			}
		}
	}
	int j;
	//状态更新
	for (int num = 2;num < len;++num)
	{
		for (int i = 0;i != len;++i)
		{
			j = i + num;
			if (j >= len) break;
			if (bin[i + 1][j - 1] && s[i] == s[j])
			{
				bin[i][j] = true;
				start = i;
				maxLen = num + 1;
			}
		}
	}
	return s.substr(start, maxLen);
}

/* 
 *	Expand Around Center
 *	时间复杂度O(n2),空间复杂度O(1)
 *	We observe that a palindrome mirrors around its center. Therefore, a palindrome can be expanded from its center, 
 *	and there are only 2n - 1 such centers. 
 *	You might be asking why there are 2n - 1 but not n centers? The reason is the center of a palindrome can be in between two letters. 
 *	Such palindromes have even number of letters (such as "abba") and its center are between the two ’b’s.
 *	(2n - 1 = n + (n - 1),n-1是含有n个元素的数组的空隙)
 */

// subLongestPalindrome中left和right最终停止的位置是回文数列的左端和右端,即(s[left]...s[right])不是一个回文,但(s[left+1]...s[right-1]是回文)
int subLongestPalindrome(string &s, int left, int right, const int len)
{
	while (left >= 0 && right < len && s[left] == s[right])
	{
		--left;
		++right;
	}
	return right - left - 1;	//right-left-1 = (right-1) - (left+1) + 1
}

string longestPalindrome(string s)
{
	if (s.empty()) return "";
	int start(0), maxLen(1), len1, len2, len(s.size());
	for (int i = 0;i != len;++i)
	{
		len1 = subLongestPalindrome(s, i, i, len);	//若回文是一个奇数数列,则此时有唯一的中心i
		len2 = subLongestPalindrome(s, i, i + 1,len);	//若回文是偶数数列,则有两个中心i,i+1
		if (len1 > maxLen)
		{
			maxLen = len1;
			start = i - (maxLen - 1) / 2;	//求得回文的开始位置
		}
		if (len2 > maxLen)
		{
			maxLen = len2;
			start = i - (maxLen - 1) / 2;
		}
	}
	return s.substr(start, maxLen);
}