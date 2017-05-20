//leetcode No.94 Binary Tree Inorder Traversal 

/*
 *	Given a binary tree, return the inorder traversal of its nodes' values.
 */

vector<int> inorderTraversal(TreeNode* root)
{
	stack<pair<TreeNode*, bool>> bin;
	vector<int> ans;
	if (!root) return ans;
	bin.push(make_pair(root, false));
	while (!bin.empty())
	{
		pair<TreeNode*, bool>& tmp = bin.top();
		if (tmp.second)
		{
			ans.push_back(tmp.first->val);
			bin.pop();
			if (tmp.first->right) bin.push(make_pair(tmp.first->right, false));
		}
		else
		{
			tmp.second = true;
			if (tmp.first->left) bin.push(make_pair(tmp.first->left, false));
		}
	}
	return ans;
}