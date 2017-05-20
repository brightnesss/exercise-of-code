// leetcode No.409 Longest Palindrome

/*
 *	Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.
 *	This is case sensitive, for example "Aa" is not considered a palindrome here.
 *	Example: 
 *	Input:
 *	"abccccdd"

 *	Output:
 *	7

 *	Explanation:
 *	One longest palindrome that can be built is "dccaccd", whose length is 7.
 */

int longestPalindrome(string s)
{
	unordered_map<char, unsigned int> bin;
	for (auto i : s) ++bin[i];
	int ans(0), temp(0);
	for (auto i : bin)
	{
		if (i.second % 2 == 0) ans += i.second;
		else if (i.second > temp)
		{
			if (temp > 1) ans += temp - 1;
			temp = i.second;
		}
		else
		{
			if (i.second > 1) ans += i.second - 1;
		}
	}
	ans += temp;
	return ans;
}