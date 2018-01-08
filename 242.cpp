/*
 *	242. Valid Anagram
 *	Given two strings s and t, write a function to determine if t is an anagram of s.

 *	For example,
	s = "anagram", t = "nagaram", return true.
	s = "rat", t = "car", return false.

 *	Note:
	You may assume the string contains only lowercase alphabets.
 */

bool isAnagram(string s, string t) 
{
    if (s.size()!=t.size()) return false;
    map<char,int> m;
    for (int i=0;i!=s.size();++i)
    {
        ++m[s[i]];
        --m[t[i]];
    }
    for (auto item:m)
    {
        if (item.second!=0) return false;
    }
    return true;
}