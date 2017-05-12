//leetcode No.451 Sort Characters By Frequency 

/*
 *	Given a string, sort it in decreasing order based on the frequency of characters.
 *	Example: 
 *	Input:
 *	"tree"

 *	Output:
 *	"eert"

 *	Explanation:
 *	'e' appears twice while 'r' and 't' both appear once.
 *	So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
 */

bool cmpBin(pair<char, int> a, pair<char, int> b)
{
	if (a.second > b.second) return true;
	else return false;
}

string frequencySort(string s)
{
	map<char, int> tmp;
	for (int i = 0;i != s.size();++i) ++tmp[s[i]];
	vector<pair<char, int>> bin(tmp.begin(), tmp.end());
	sort(bin.begin(), bin.end(), cmpBin);
	string ans;
	for (auto i : bin)
	{
		if (i.second == 0) break;
		for (int j = 0;j != i.second;++j) ans += i.first;
	}
	return ans;
}