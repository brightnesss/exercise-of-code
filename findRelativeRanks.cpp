// leetcode No.506 Relative Ranks

/*
 *	Given scores of N athletes, find their relative ranks and the people with the top three highest scores
 *	who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".
 *	Example:
 *	Input:[3,8,4,9,1]
 *	Output:["4","Silver Medal","Bronze Medal","Gold Medal","5"];
 */

#include "inlcudelib.h"

vector<string> findRelativeRanks(vector<int>& nums)
{
	vector<pair<int, int>> num;
	for (int i = 0;i != nums.size();++i)
	{
		num.push_back(make_pair(nums[i], i));
	}
	sort(num.begin(), num.end(), [](pair<int, int>a, pair<int, int>b) {return a.first >= b.first;});
	vector<string> ans(nums.size());
	for (int i = 0;i != nums.size();++i)
	{
		if (i == 0) ans[num[i].second] = "Gold Medal";
		else if (i == 1) ans[num[i].second] = "Silver Medal";
		else if (i == 2) ans[num[i].second] = "Bronze Medal";
		else ans[num[i].second] = to_string(i + 1);
	}
	return ans;
}