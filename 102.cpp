//leetcode No.102 Binary Tree Level Order Traversal

/*
 *	Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

 *	For example:
 *	Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7

 *	return its level order traversal as:
	[
  	 [3],
  	 [9,20],
  	 [15,7]
	]
 */

vector<vector<int>> levelOrder(TreeNode* root)
{
	if (!root) return vector<vector<int>>();
	vector<vector<int>> ans;
	ans.push_back(vector<int>(1, root->val));
	queue<pair<TreeNode*, bool>> bin;
	bin.push(make_pair(root, false));

	pair<TreeNode*, bool> tmp;
	vector<int> layer;
	while (!bin.empty())
	{
		tmp = bin.front();
		if (!tmp.second)
		{
			if (tmp.first->left) layer.push_back(tmp.first->left->val);
			if (tmp.first->right) layer.push_back(tmp.first->right->val);
			bin.pop();
			bin.push(make_pair(tmp.first, true));
		}
		else
		{
			if (!layer.empty()) ans.push_back(layer);
			layer.clear();
			bin.pop();
			if (tmp.first->left) bin.push(make_pair(tmp.first->left, false));
			if (tmp.first->right) bin.push(make_pair(tmp.first->right, false));
		}
	}
	return ans;
}