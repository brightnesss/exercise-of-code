/*
 *	Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 *	Each number in C may only be used once in the combination.

 *	Note:
 *	All numbers (including target) will be positive integers.
 *	The solution set must not contain duplicate combinations.
 *	For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
 *	A solution set is: 
	[
  	 [1, 7],
  	 [1, 2, 5],
   	 [2, 6],
   	 [1, 1, 6]
	]
 */

//回溯法
void subcombinationSum2(vector<vector<int>>& ans, vector<int> tmp, vector<int>& candidates, int target, int begin)
{
	for (int i = begin+1;i < candidates.size();++i)
	{
		if (i > begin + 1 && candidates[i] == candidates[i - 1]) continue;
		if (target < candidates[i]) break;
		else if (target == candidates[i])
		{
			tmp.push_back(candidates[i]);
			ans.push_back(tmp);
		}
		else
		{
			tmp.push_back(candidates[i]);
			subcombinationSum(ans, tmp, candidates, target - candidates[i], i);
			tmp.pop_back();
		}
	}
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
{
	sort(candidates.begin(), candidates.end());
	vector<vector<int>> ans;
	vector<int> tmp;
	for (int i = 0;i != candidates.size();++i)
	{
		tmp.clear();
		if (i > 0 && candidates[i] == candidates[i - 1]) continue;
		if (candidates[i] > target) break;
		else if (candidates[i] == target)
		{
			ans.push_back(vector<int>{candidates[i]});
			break;
		}
		else
		{
			tmp.push_back(candidates[i]);
			subcombinationSum2(ans, tmp, candidates, target - candidates[i], i);
		}
	}
	return ans;
}