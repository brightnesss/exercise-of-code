//leetcode No.347 Top K Frequent Elements 

/*
 *	Given a non-empty array of integers, return the k most frequent elements.
 *	For example,
 *	Given [1,1,1,2,2,3] and k = 2, return [1,2]. 
 *	Note: 
 *	You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 *	Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
 */

//基本想法肯定是用map计算频率,要实现比O(nlogn)更快的效率，应该是要用堆,可以达到O(klogn)
//学会了如何使用stl中的堆...

vector<int> topKFrequent(vector<int>& nums, int k)
{
	unordered_map<int, int> map;
	for (auto i : nums) ++map[i];
	priority_queue<pair<int, int>> bin;
	for (auto i : map) bin.push(make_pair(i.second, i.first));
	vector<int> ans;
	for (int i = 0;i != k;++i)
	{
		ans.push_back(bin.top().second);
		bin.pop();
	}
	return ans;
}