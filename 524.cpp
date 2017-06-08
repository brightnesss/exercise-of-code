//leetcode No.524 Longest Word in Dictionary through Deleting 

/*
 *	Given a string and a string dictionary, find the longest string in the dictionary that can be formed by deleting some characters of the given string.
 *	If there are more than one possible results, return the longest word with the smallest lexicographical order. 
 *	If there is no possible result, return the empty string. 

 *	Example 1:
 *	Input:
 *	s = "abpcplea", d = ["ale","apple","monkey","plea"]

 *	Output: 
 *	"apple"


 *	Example 2:
 *	Input:
 *	s = "abpcplea", d = ["a","b","c"]

 *	Output: 
 *	"a"

 *	Note:
 *	All the strings in the input will only contain lower-case letters.
 *	The size of the dictionary won't exceed 1,000.
 *	The length of all the strings in the input won't exceed 1,000.
 */

bool findWordCmp(const string a, const string b)
{
	/*
	 *	排序比较函数
	 *	当两个字符串长度相同时,返回它们按字典序列排序的结果
	 *	当长度不等时,比较长度
	 */
	if (a.size() == b.size()) return a < b;
	else return a.size() > b.size();
}

bool findWord(const string s, const string d)
{
	//判断是否为子串
	if (s.size() < d.size()) return false;
	else if (s.size() == d.size()) return s == d;
	else
	{
		int begin(0), end;
		bool isfind(true);
		for (char c : d)
		{
			end = s.find_first_of(c, begin);
			if (end == string::npos)
			{
				isfind = false;
				break;
			}
			else begin = end + 1;
		}
		return isfind;
	}
}

string findLongestWord(string s, vector<string>& d)
{
	//先排序,使得比较的顺序按照题目要求
	sort(d.begin(), d.end(), findWordCmp);
	unordered_map<char, int> strings, stringd;
	for (char c : s) ++strings[c];
	for (string tmps : d)
	{
		bool isfind = findWord(s, tmps);
		if (isfind) return tmps;
		else continue;
	}
	return string();
}