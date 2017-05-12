//leetcode No.438 Find All Anagrams in a String 

/*
 *	Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
 *	Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.
 *	The order of output does not matter.

 *	Example 1: 
 *	Input:
 *	s: "cbaebabacd" p: "abc"
	
 *	Output:
 *	[0, 6]
	
 *	Explanation:
 *	The substring with start index = 0 is "cba", which is an anagram of "abc".
 *	The substring with start index = 6 is "bac", which is an anagram of "abc".
 */


//因为是不计顺序的，只记出现次数，用sliding window的方法可以快速实现
//mode是记录模式p的字母出现次数
//str是记录当前window中的字母出现次数
//若str==mode，则是一个答案
vector<int> findAnagrams(string s, string p)
{
	unordered_map<char, int> str, mode;
	vector<int> ans;
	if (s.size() < p.size()) return ans;
	for (int i = 0;i != p.size();++i)
	{
		++str[s[i]];
		++mode[p[i]];
	}
	if (str == mode) ans.push_back(0);
	int len = p.size();
	for (int i = p.size();i != s.size();++i)
	{
		++str[s[i]];
		if (--str[s[i - len]] == 0) str.erase(s[i - len]); //必须要删除
		if (str == mode) ans.push_back(i - len + 1);
	}
	return ans;
}