
// leetcode No.226 Invert Binary Tree

//考非递归的树遍历？

#include "includelib.h"

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* invertTree(TreeNode* root)
{
	stack<TreeNode*> binTree;
	if (root)
	{
		binTree.push(root);
		while (!binTree.empty())
		{
			TreeNode* top = binTree.top();
			binTree.pop();
			swap(top->left, top->right);
			if (top->left) binTree.push(top->left);
			if (top->right) binTree.push(top->right);
		}
	}
	return root;
}

TreeNode* invertTree(TreeNode* root)
{
	if (!root) return root;
	swap(root->left, root->right);
	if (root->left) invertTree(root->left);
	if (root->right) invertTree(root->right);
	return root;
}