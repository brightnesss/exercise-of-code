// leetcode No.110 Balanced Binary Tree

/*
 *	Given a binary tree, determine if it is height-balanced. 
 *	For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 
 */

int heightOfTree(TreeNode* root)	
{
	//求树的深度
	if (!root) return 0;
	else
	{
		int lHeight = heightOfTree(root->left);
		int rHeight = heightOfTree(root->right);
		return lHeight >= rHeight ? lHeight + 1 : rHeight + 1;
	}
}

bool isBalanced(TreeNode* root)
{
	//判断是否是平衡树
	if (!root) return true;
	else
	{
		int lheight = heightOfTree(root->left);
		int rheight = heightOfTree(root->right);
		if (abs(lheight - rheight) > 1) return false;	//高度差大于1就不是了
		else return (isBalanced(root->left) && isBalanced(root->right));	//左右子树都是平衡的root才是平衡的
	}
}