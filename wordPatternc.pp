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