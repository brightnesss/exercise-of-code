/*
 *	131. Palindrome Partitioning
 *	Given a string s, partition s such that every substring of the partition is a palindrome.
 *	Return all possible palindrome partitioning of s.

 *	For example, given s = "aab",
 	Return
	[
  	 ["aa","b"],
  	 ["a","a","b"]
	]
 */

/*
 *	回溯法
 */

bool isPartition_131(string s)
{
	string par = s;
	reverse(par.begin(), par.end());
	return par == s;
}

void subPartition_131(const string s, int start, vector<string> &tmp, vector<vector<string>> &ans)
{
	if (start == s.size()) ans.push_back(tmp);
	for (int i = start;i < s.size();++i)
	{
		if (isPartition_131(s.substr(start, i - start + 1)))
		{
			tmp.push_back(s.substr(start, i - start + 1));
			subPartition_131(s, i + 1, tmp, ans);
			tmp.pop_back();
		}
	}
}

vector<vector<string>> partition_131(string s)
{
	vector<vector<string>> ans;
	if (s.empty()) return ans;
	int len(s.size());
	vector<string> tmp;
	subPartition_131(s, 0, tmp, ans);
	return ans;
}