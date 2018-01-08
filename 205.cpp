/*
 *	205. Isomorphic Strings
 *	Given two strings s and t, determine if they are isomorphic.
 *	Two strings are isomorphic if the characters in s can be replaced to get t.
 *	All occurrences of a character must be replaced with another character while preserving the order of characters. 
 	No two characters may map to the same character but a character may map to itself.

 *	For example,
	Given "egg", "add", return true.
	Given "foo", "bar", return false.
	Given "paper", "title", return true.

 *	Note:
	You may assume both s and t have the same length.
 */

/*
 *	实际上只要判断s和t是否符合一个相同的模板就行了,这个模板我们打算自己重新构造
 *	将s和t的每一个字符都重新按顺序编码,若编码在过程中已经不同了,则说明他们符合的规范不同
 *	比如:"egg"->"abb","add"->"abb",都符合abb的模板
 	"foo"->"abb","bar"->"abc",符合的模板不同
 	"paper"->"abacd","title"->"abacd",符合的模板相同
 */
bool isIsomorphic(string s, string t)
{
	map<char, char> ms, mt;
	int len(s.size());
	char cs('a'), ct('a');
	for (int i = 0;i != len;++i)
	{
		if (ms.find(s[i]) == ms.end())
		{
			ms[s[i]] = cs;
			s[i] = cs;
			cs += 1;
		}
		else s[i] = ms[s[i]];
		if (mt.find(t[i]) == mt.end())
		{
			mt[t[i]] = ct;
			t[i] = ct;
			ct += 1;
		}
		else t[i] = mt[t[i]];
		if (ct != cs) return false;
	}
	return s == t;
}