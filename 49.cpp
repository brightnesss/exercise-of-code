/*
 *	49. Group Anagrams
 *	Given an array of strings, group anagrams together.

 *	For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
 *	Return:
	[
  	 ["ate", "eat","tea"],
  	 ["nat","tan"],
  	 ["bat"]
	]
 *	Note: All inputs will be in lower-case.
 */

//超时
//时间复杂度O(n2)
vector<vector<string>> groupAnagrams(vector<string>& strs)
{
	vector<pair<string, bool>> bin;
	for (string str : strs) bin.push_back(make_pair(str, false));
	vector<vector<string>> ans;
	vector<string> tmp;
	vector<int> count1(26, 0), count2;
	for (int i = 0;i != bin.size();++i)
	{
		if (bin[i].second) continue;
		tmp.clear();
		fill_n(count1.begin(), 26, 0);
		string str = bin[i].first;
		tmp.push_back(str);
		for (char c : str) ++count1[c - 'a'];
		for (int j = i + 1;j != bin.size();++j)
		{
			if (bin[j].second) continue;
			count2 = count1;
			string s = bin[j].first;
			if (s.size() != str.size()) continue;
			for (char c : s) --count2[c - 'a'];
			int index(0);
			for (;index != 26;++index)
			{
				if (count2[index] == 0) continue;
				else break;
			}
			if (index == 26)
			{
				tmp.push_back(s);
				bin[j].second = true;
			}
		}
		ans.push_back(tmp);
	}
	return ans;
}

//用一个map来记录,通过对每一个str进行排序,使得所有相同的anagrams可以成为同样的序列,即可以作为key
//时间复杂度O(nlogk) k=max(str.size() in strs)
vector<vector<string>> groupAnagrams_v2(vector<string>& strs)
{
	unordered_map<string, vector<string>> bin;
	for (string s : strs)
	{
		string str = s;
		sort(str.begin(), str.end());
		bin[str].push_back(s);
	}
	vector<vector<string>> ans;
	for (auto item : bin)
	{
		ans.push_back(item.second);
	}
	return ans;
}