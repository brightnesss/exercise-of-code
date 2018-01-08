/*
 *	30. Substring with Concatenation of All Words
 *	You are given a string, s, and a list of words, words, that are all of the same length. 
 *	Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once 
 *	and without any intervening characters.

 *	For example, given:
	s: "barfoothefoobarman"
	words: ["foo", "bar"]
 *	You should return the indices: [0,9].
 *	(order does not matter).
 *	words数组中会出现重复的词,但返回的结果中不应该出现相同的位置
 */

/*
 *	超时,思路类似回溯
 *	遍历每一种可能的字符组成,若有一种刚好能够在s中找到,则将起始位置推入
 */
void subFindSubstring(const string s, int pos, vector<pair<string, bool>> &bin, set<int> &ans, const int wordlen)
{
	bool complete(true);	//若所有的字符都被用过了,说明找到了一个这样的可能
	for (int i = 0;i != bin.size();++i)
	{
		if (bin[i].second) continue;
		else
		{
			complete = false;
			if (s.substr(pos, wordlen) == bin[i].first)	//若s的下一个刚好就是该子字符串
			{
				bin[i].second = true;
				subFindSubstring(s, pos + wordlen, bin, ans, wordlen);
				bin[i].second = false;
			}
		}
	}
	if (complete) ans.insert(pos - wordlen*bin.size());
}

vector<int> findSubstring(string s, vector<string>& words)
{
	if (s.empty() || words.empty()) return vector<int>{};
	set<int> ans;
	int len(s.size()), sublen(words.size()*words[0].size()), wordlen(words[0].size());
	vector<pair<string, bool>> bin;
	for (string str : words) bin.push_back(make_pair(str, false));
	for (int i = 0;i != bin.size();++i)
	{
		//以每一个字符都有可能为起始
		bin[i].second = true;	//标志该字符被用过
		int begin(0);	
		begin = s.find(bin[i].first,begin);	//在s中寻找这个字符的所有出现位置
		while (begin != string::npos)
		{
			if (begin + sublen > len) break;	//若这个位置之后已经不能容纳所有的words的子字符串,则遍历下一个
			else
			{
				subFindSubstring(s, begin + wordlen, bin, ans, wordlen);
				begin = s.find(bin[i].first, begin + 1);
			}
		}
		bin[i].second = false;
	}
	vector<int> final_ans;
	for (int val : ans) final_ans.push_back(val);
	return final_ans;
}

/*
 *	用两个map来分别存放words中的string的个数和在s中搜索时见到的string的个数
 *	用map可能速度确实会快很多,但整体的思路没有变化,还是遍历所有可能的情况
 */
vector<int> findSubstring(string s, vector<string>& words)
{
	if (s.empty() || words.empty()) return vector<int>{};
	vector<int> ans;
	int len(s.size()), sublen(words.size()*words[0].size()), wordlen(words[0].size()), num(words.size());
	unordered_map<string, int> have;
	for (string str : words) ++have[str];
	string str;
	for (int i = 0;i <= len - sublen;++i)
	{
		int j(0);
		unordered_map<string, int> seen;
		for (;j < num;++j)
		{
			str = s.substr(i + j*wordlen, wordlen);
			if (have.find(str) != have.end())
			{
				++seen[str];
				if (seen[str] > have[str]) break;
			}
			else break;
		}
		if (j == num) ans.push_back(i);
	}
	return ans;
}