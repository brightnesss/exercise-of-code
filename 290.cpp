//leetcode No.290 Word Pattern 
/*
 *	Given a pattern and a string str, find if str follows the same pattern.
 *	Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.
 *	Examples:
 *	pattern = "abba", str = "dog cat cat dog" should return true.
 *	pattern = "abba", str = "dog cat cat fish" should return false.
 *	pattern = "aaaa", str = "dog cat cat dog" should return false.
 *	pattern = "abba", str = "dog dog dog dog" should return false.
	
 *	Notes:
 *	You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space. 
 */

//分别用两个map建立pattern和str之间的一对一映射关系
//提前读取str进tmp可以判断大量的case是不符合的（pattern和str的长度就不同），节省时间
bool wordPattern(string pattern, string str)
{
	unordered_map<char, string> bin;
	unordered_map<string, char> s;
	vector<string> tmp;
	istringstream in(str);
	string word;
	while (in >> word) tmp.push_back(word);
	if (tmp.size() != pattern.size()) return false;
	int count(0);
	while (count!=tmp.size())
	{
		if (bin.find(pattern[count]) == bin.end()) bin[pattern[count]] = tmp[count];
		else
		{
			if (bin[pattern[count]] != tmp[count]) return false;
		}
		if (s.find(tmp[count]) == s.end()) s[tmp[count]] = pattern[count];
		else
		{
			if (s[tmp[count]] != pattern[count]) return false;
		}
		++count;
	}
	return true;
}

//a better one
bool wordPattern(string pattern,string str)
{
	unordered_map<char,int> bin;
	unordered_map<string,int> s;
	istringstream in(str);
	string word;
	int count(0),len=pattern.size();
	while(in>>word)
	{
		if (bin[pattern[count]]!=s[word]) return false;
		//这里count+1仅仅是一个记号，没有其他含义
		else bin[pattern[count]]=s[word]=count+1; //这里+1是必须的，防止首次插入的（int默认为0）和第一次循环中插入的（那时count=0）相等
		++count;
	}
	return count==len;
}