//leetcode No.399 Evaluate Division 

/*
 *	Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0. 
 
 *	Example:
 *	Given a / b = 2.0, b / c = 3.0. 
 *	queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? . 
 *	return [6.0, 0.5, -1.0, 1.0, -1.0 ]. 
 *	The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , where equations.size() == values.size(), and the values are positive. This represents the equations. Return vector<double>. 
 *	According to the example above: 
 *	equations = [ ["a", "b"], ["b", "c"] ],
 *	values = [2.0, 3.0],
 *	queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 

 *	The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction. 
 */


//深度优先搜索
double check(string up, string down, unordered_map<string, unordered_map<string, double>> &bin, unordered_set<string> &v)
{
	if (bin[up].find(down) != bin[up].end()) return bin[up][down];
	else
	{
		for (auto i : bin[up])
		{
			if (v.find(i.first) == v.end())
			{
				v.insert(i.first);
				double tmp = check(i.first, down, bin, v);
				if (tmp) return i.second*tmp;
			}
		}
		return 0;
	}
}

vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries)
{
	unordered_map<string, unordered_map<string, double>> bin;
	unordered_set<string> variables;
	for (int i = 0;i != values.size();++i)
	{
		variables.insert(equations[i].first);
		variables.insert(equations[i].second);
		bin[equations[i].first].insert(make_pair(equations[i].second, values[i]));
		if (values[i] != 0) bin[equations[i].second].insert(make_pair(equations[i].first, 1.0 / values[i]));
	}
	vector<double> ans;
	for (auto i : queries)
	{
		if (variables.find(i.first) == variables.end() || variables.find(i.second) == variables.end()) ans.push_back(-1);
		else if (i.first == i.second) ans.push_back(1.0);
		else
		{
			unordered_set<string> v;
			double tmp = check(i.first, i.second, bin, v);
			if (tmp) ans.push_back(tmp);
			else ans.push_back(-1);
		}
	}
	return ans;
}