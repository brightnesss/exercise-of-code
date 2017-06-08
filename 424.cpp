//leetcode No.424 Longest Repeating Character Replacement 

/*
 *	Given a string that consists of only uppercase English letters, you can replace any letter in the string with another letter at most k times. Find the length of a longest substring containing all repeating letters you can get after performing the above operations.
 *	Note:
 *	Both the string's length and k will not exceed 104. 
 *	Example 1: 
 *	Input:
 *	s = "ABAB", k = 2

 *	Output:
 *	4

 *	Explanation:
 *	Replace the two 'A's with two 'B's or vice versa.

 *	Example 2: 
 *	Input:
 *	s = "AABABBA", k = 1

 *	Output:
 *	4

 *	Explanation:
 *	Replace the one 'A' in the middle with 'B' and form "AABBBBA".
 *	The substring "BBBB" has the longest repeating letters, which is 4.
 */


/*
 *	sliding window,用begin和end分别标记window的开始和结尾,则end-begin+1为window的长度
 *	maxChar为window中频率最高的字母的出现次数,则最长的长度ans=maxChar+k=end-begin+1
 *	若end-begin+1-maxChar>k,说明这个window不是答案,将begin后移,同时要注意更新maxChar
 */
int characterReplacement(string s, int k)
{
	vector<int> bin(26, 0);
	int ans(0), maxChar(0);
	int begin(0), end(0);
	for (;end != s.size();++end)
	{
		++bin[s[end] - 'A'];
		if (bin[s[end] - 'A'] > maxChar) maxChar = bin[s[end] - 'A'];
		while (end - begin + 1 - maxChar > k)
		{
			--bin[s[begin] - 'A'];
			++begin;
			for (int i = 0;i != 26;++i) if (bin[i] > maxChar) maxChar = bin[i];
		}
		ans = max(ans, end - begin + 1);
	}
	return ans;
}