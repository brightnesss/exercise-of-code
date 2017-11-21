/*
 *	106. Construct Binary Tree from Inorder and Postorder Traversal
 *	Given inorder and postorder traversal of a tree, construct the binary tree.
 *	Note:
 *	You may assume that duplicates do not exist in the tree.
 */

/*
 *	和105题思路相同
 *	唯二不同的是
 *	1. 对index的处理
 *	2. 后续遍历是先right后left,前序遍历是先left后right
 */


TreeNode* subBuildTree_106(TreeNode* root, vector<int>& postorder, vector<int>& inorder, int index)
{
	if (index < 0) return root;
	if (inorder.empty()) return root;
	vector<int> left{}, right{};
	root = new TreeNode(postorder[index]);
	int i(0);
	for (;i != inorder.size();++i)
	{
		if (root->val == inorder[i])
		{
			left.assign(inorder.begin(), inorder.begin() + i);
			if (i + 1 < inorder.size()) right.assign(inorder.begin() + i + 1, inorder.end());
			break;
		}
	}
	root->right = subBuildTree_106(root->right, postorder, right, index - 1);
	root->left = subBuildTree_106(root->left, postorder, left, index - (inorder.size() - i));
	return root;
}

TreeNode* buildTree_106(vector<int>& inorder, vector<int>& postorder)
{
	TreeNode* root = NULL;
	if (postorder.empty()) return root;
	else
	{
		int index(postorder.size() - 1), i(0);
		vector<int> left{}, right{};
		root = new TreeNode(postorder[index]);
		for (;i != inorder.size();++i)
		{
			if (root->val == inorder[i])
			{
				left.assign(inorder.begin(), inorder.begin() + i);
				if (i + 1 < inorder.size()) right.assign(inorder.begin() + i + 1, inorder.end());
				break;
			}
		}
		root->right = subBuildTree_106(root->right, postorder, right, index - 1);
		root->left = subBuildTree_106(root->left, postorder, left, index - (inorder.size() - i));
		return root;
	}
}