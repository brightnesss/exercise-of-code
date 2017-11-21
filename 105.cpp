/*
 *	105. Construct Binary Tree from Preorder and Inorder Traversal
 *	Given preorder and inorder traversal of a tree, construct the binary tree.
 *	Note:
 *	You may assume that duplicates do not exist in the tree.
 */

//递归的方法,前序的点可以将中序数组分为左右两部分,一部分左,一部分右,如此循环下去,直到中序数组为空,说明该叶子结点也为空
TreeNode* subBuildTree(TreeNode* root, vector<int>& preorder, vector<int>& inorder, int index)
{
	if (index >= preorder.size()) return root;
	if (inorder.empty()) return root;
	root = new TreeNode(preorder[index]);
	int i(0);
	vector<int> left{}, right{};
	for (;i != inorder.size();++i)
	{
		if (inorder[i] == root->val)
		{
			left.assign(inorder.begin(), inorder.begin() + i);
			if (i + 1 < inorder.size()) right.assign(inorder.begin() + i + 1, inorder.end());
			break;
		}
	}
	root->left = subBuildTree(root->left, preorder, left, index + 1);
	root->right = subBuildTree(root->right, preorder, right, index + i + 1);
	return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
	TreeNode* root = NULL;
	if (preorder.empty()) return root;
	else
	{
		root = new TreeNode(preorder[0]);
		vector<int> left{}, right{};
		int index(0), i(0);
		for (;i != inorder.size();++i)
		{
			if (inorder[i] == root->val)
			{
				left.assign(inorder.begin(), inorder.begin() + i);
				if (i + 1 < inorder.size()) right.assign(inorder.begin() + i + 1, inorder.end());
				break;
			}
		}
		root->left = subBuildTree(root->left, preorder, left, index + 1);
		root->right = subBuildTree(root->right, preorder, right, index + i + 1);
	}
	return root;
}