//leetcode No.508 Most Frequent Subtree Sum

/*
 *	Given the root of a tree, you are asked to find the most frequent subtree sum. The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself). So what is the most frequent subtree sum value? If there is a tie, return all the values with the highest frequency in any order. 
 *	Examples 1
 *	Input: 
	    5
 	   /  \
	  2   -3
 *	return [2, -3, 4], since all the values happen only once, return all of them in any order. 

 *	Examples 2
 *	Input: 
  		   5
 		 /  \
		2   -5
 *	return [2], since 2 happens twice, however -5 only occur once. 
 */ 

int treeSum(TreeNode *root, unordered_map<int, int>& bin)
{
	if (!root) return 0;
	int val = root->val + treeSum(root->left, bin) + treeSum(root->right, bin);
	++bin[val];
	return val;
}

vector<int> findFrequentTreeSum(TreeNode* root)
{
	vector<int> ans;
	if (!root) return ans;
	unordered_map<int, int> bin;
	treeSum(root, bin);
	int maxFrequent(0);
	for (auto i : bin) maxFrequent = maxFrequent > i.second ? maxFrequent : i.second;
	for (auto i : bin)
	{
		if (maxFrequent == i.second) ans.push_back(i.first);
	}
	return ans;
}