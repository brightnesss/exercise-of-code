//leetcode No.14 Longest Common Prefix

/*
 *	Write a function to find the longest common prefix string amongst an array of strings. 
 */

string::iterator matchSubStr(string &strs, string &substr)
{
	//substr的长度小于等于strs的长度
	//找到strs中第一个与substr不匹配的位置
	string::iterator ans = substr.begin(), pos = strs.begin();
	while (ans != substr.end())
	{
		if (*ans == *pos)
		{
			++ans;
			++pos;
		}
		else break;
	}
	return ans;
}



string longestCommonPrefix(vector<string>& strs)
{
	//用strs中长度最小的string作为substr与其他的string匹配，
	//若不匹配，则将不匹配的字段删除
	//返回最终的substr，即为要求的最长前缀
	string shortestStr;
	int length = INTMAX_MAX;
	for (auto i : strs)
	{
		if (i.size() < length)
		{
			shortestStr = i;
			length = i.size();
		}
	}
	for (auto i : strs)
	{
		if (shortestStr.empty()) break;
		string::iterator it = matchSubStr(i, shortestStr);
		if (it == shortestStr.end()) continue;
		else shortestStr.erase(it, shortestStr.end());
	}
	return shortestStr;
}