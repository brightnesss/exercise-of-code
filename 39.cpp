/*
 *	Given a set of candidate numbers (C) (without duplicates) and a target number (T), 
 *	find all unique combinations in C where the candidate numbers sums to T.
 *	The same repeated number may be chosen from C unlimited number of times.

 *	Note:
 *	All numbers (including target) will be positive integers.
 *	The solution set must not contain duplicate combinations.
 *	For example, given candidate set [2, 3, 6, 7] and target 7, 

	A solution set is: 
	[
  	 [7],
  	 [2, 2, 3]
	]
 */

void subcombinationSum(vector<vector<int>>& ans, vector<int> tmp, vector<int>& candidates ,int target, int begin)
{
	for (int i = begin;i != candidates.size();++i)
	{
		if (target == candidates[i])
		{
			tmp.push_back(candidates[i]);
			ans.push_back(tmp);
		}
		else if (target < candidates[i]) break;
		else
		{
			tmp.push_back(candidates[i]);
			subcombinationSum(ans, tmp, candidates, target - candidates[i], i);
			tmp.pop_back();
		}
	}
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
	sort(candidates.begin(), candidates.end());
	vector<int> tmp;
	vector<vector<int>> ans;
	for (int i = 0;i != candidates.size();++i)
	{
		tmp.clear();
		if (target == candidates[i])
		{
			ans.push_back(vector<int>{candidates[i]});
			break;
		}
		if (target < candidates[i]) break;
		else
		{
			tmp.push_back(candidates[i]);
			subcombinationSum(ans, tmp, candidates, target - candidates[i], i);
		}
	}
	return ans;
}