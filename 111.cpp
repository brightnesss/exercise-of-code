// leetcode No.111 Minimum Depth of Binary Tree 

/*
 *	Given a binary tree, find its minimum depth.
 *	The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
 */

int depth(TreeNode* root)
{
	if (!root) return 0;
	if (root->left || root->right)
	{
		int l = depth(root->left);
		int r = depth(root->right);
		if (root->left && root->right) return min(l,r) + 1;
		else if (root->left) return l + 1;
		else return  r + 1;
	}
	else return 1;
}

int minDepth(TreeNode* root)
{
	return depth(root);
}

int minDepth(TreeNode* root) 
{
    if (!root) return 0;
    if (root->left&&root->right) return min(minDepth(root->left),minDepth(root->right))+1;
    else if (root->left) return minDepth(root->left)+1;
    else if (root->right) return minDepth(root->right)+1;
    else return 1;
}