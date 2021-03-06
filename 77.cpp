//leetcode No.77 Combinations

/*
 *Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

 *	For example,
 *	If n = 4 and k = 2, a solution is:

	[
  	 [2,4],
  	 [3,4],
  	 [2,3],
  	 [1,2],
   	 [1,3],
  	 [1,4],
	]
 */


//和leetcode46还有leetcode78相似
void combine(vector<vector<int>> &ans, vector<int> tmp, const int k, const int n, int begin)
{
	if (tmp.size() == k)
	{
		ans.push_back(tmp);
		return;
	}
	for (int i = begin;i < n;++i)
	{
		tmp.push_back(i + 1);
		combine(ans, tmp, k, n, i + 1);
		tmp.pop_back();
	}
}

vector<vector<int>> combine(int n, int k)
{
	vector<vector<int>> ans;
	if (n < k) return ans;
	if (n == k)
	{
		vector<int> tmp;
		for (int i = 0;i != n;++i) tmp.push_back(i + 1);
		ans.push_back(tmp);
		return ans;
	}
	combine(ans, vector<int>(), k, n, 0);
	return ans;
}

//二刷,写出来的还是差不多的代码...
void subCombine(vector<vector<int>> &ans, vector<int> &num, const int n, int k, int end)
{
	if (k == 0)
	{
		ans.push_back(num);
		return;
	}
	int begin = end + 1;
	for (int i = begin;i <= n - k + 1;++i)
	{
		num.push_back(i);
		subCombine(ans, num, n, k - 1, i);
		num.pop_back();
	}
}

vector<vector<int>> combine(int n, int k)
{
	vector<vector<int>> ans;
	vector<int> num;
	subCombine(ans, num, n, k, 0);
	return ans;
}