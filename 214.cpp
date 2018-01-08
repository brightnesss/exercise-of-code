/*
 *	214. Shortest Palindrome
 *	Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. 
 *	Find and return the shortest palindrome you can find by performing this transformation.

 *	For example:
	Given "aacecaaa", return "aaacecaaa".
	Given "abcd", return "dcbabcd".
 */

/*
 *	要求向前插入最少的字符使得s成为一个回文,可以将s翻转改为从后插入,这样效率会高一点
 *	如果最终的s_final是一个回文字符串,则有两种可能:
 		s_final的长度为奇数,则此时s_final有最中间的字符
 		s_final的长度为偶数,则此时s_final没有最中间字符,要求中间两个字符相等
 *	我们现在考虑从后面添加字符,则不论s_final是偶数个还是奇数个,s_final的最中间的字符肯定是s中间靠后位置的某一个字符
 		比如,若s为"aacecaaa",反转后为"aaacecaa",则s_final的中间字符不可能是前面三个'a',因为若以前面三个'a'为中间字符,
 		前面的字符数根本不够和后面的字符进行匹配,就需要从前面插入字符,这是不符合要求的
 *	所以我们假设中间字符从s的中后段开始,分别假设s_final是偶数和奇数,分别计算,若两种情况都有可能,则找加入字符数最小的为答案
 */

string shortestPalindrome(string s)
{
	if (s.empty()) return s;
	reverse(s.begin(), s.end());
	int len(s.size()), mid(len / 2);
	int start, end;
	string ans1, ans2;
	int ans1num, ans2num;
	for (int i = mid;i < len;++i)	//从s的中间位置开始
	{
		ans1 = ans2 = s;
		ans1num = ans2num = -1;
		start = i - 1, end = i;		//最终的回文是偶数，即中间两个是必须相等的
		while (start >= 0 || end < len)
		{
			if (s[start] == s[end])
			{
				--start;
				++end;
			}
			else break;
		}
		if (start < 0 && end >= len) return s;	//说明s就是回文,即start和begin都超过了s的界限
		else if (end >= len)
		{
			//说明这个时候s中间的部分确实是回文,可以通过在s后面添加一些字符来是s成为回文
			ans1num = start + 1;	//需要添加的字符个数就是start距离0的位置
			while (start >= 0)
			{
				ans1 += s[start];
				--start;
			}
		}
		else if (start<0) {//以i为中心不可能构成回文,因为前面已经没有字符而后面还有字符}

		start = i - 1, end = i + 1;		//最终的回文是奇数，即中间只有一个字符
		while (start >= 0 || end < len)
		{
			if (s[start] == s[end])
			{
				--start;
				++end;
			}
			else break;
		}
		if (start < 0 && end >= len) return s;
		else if (end >= len)
		{
			ans2num = start + 1;
			while (start >= 0)
			{
				ans2 += s[start];
				--start;
			}
		}
		if (ans1num != -1 || ans2num != -1)
		{
			//是否存在答案
			if (ans1num != -1 && ans2num != -1)
			{
				//两种情况都有可能,找添加字符少的那个
				return ans1num > ans2num ? ans2 : ans1;
			}
			//只有一种可能
			else if (ans1num != -1) return ans1;
			else return ans2;
		}
	}
}