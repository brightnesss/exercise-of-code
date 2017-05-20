//leetcode No.392 Is Subsequence 

/*
 *	Given a string s and a string t, check if s is subsequence of t. 
 *	You may assume that there is only lower case English letters in both s and t. t is potentially a very long (length ~= 500,000) string, and s is a short string (<=100). 
 *	A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not). 
 
 *	Example 1:
 *	s = "abc", t = "ahbgdc" 
 *	Return true. 

 *	Example 2:
 *	s = "axc", t = "ahbgdc" 
 *	Return false. 
 *	Follow up:
 *	If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T has its subsequence. 
 *	In this scenario, how would you change your code?
 */

//只有一个子串需要判断
bool isSubsequence(string s, string t)
{
	if (s.empty()) return false;
	if (s.size() > t.size()) return false;
	size_t pre = t.find_first_of(s[0]);
	if (pre == string::npos) return false;
	for (int i = 1;i != s.size();++i)
	{
		size_t pos = t.find_first_of(s[i], pre + 1);
		if (pos == string::npos) return false;
		else pre = pos;
	}
	return true;
}

//有多个子串需要判断
bool isSubsequence(string s, string t)
{
	//先用一个vector将t的结构存储起来
	//之后的思路和上面的版本很像
	if (s.empty()) return true;
	if (s.size() > t.size()) return false;
	vector<vector<int>> bin(26); //26个字母
	for (int i = 0;i != t.size();++i) bin[t[i] - 'a'].push_back(i);
	int pos(-1);
	for (int i = 0;i != s.size();++i)
	{
		int ch = s[i] - 'a';
		if (bin[ch].empty()) return false;
		vector<int>::iterator it;
		for (it = bin[ch].begin();it != bin[ch].end();++it) if (*it > pos) break;
		if (it == bin[ch].end()) return false;
		else pos = *it;
	}
	return true;
}

//当只有一个子串的时候,第一个版本速度要更快,因为第二个版本要先建立一个数组
