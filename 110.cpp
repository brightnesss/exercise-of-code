
// leetcode No.110 Balanced Binary Tree

/*
 *	Given a binary tree, determine if it is height-balanced. 
 *	For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 
 */

//自顶向下的方法,复杂度O(n2)
int heightOfTree(TreeNode* root)	
{
	//求树的深度
	if (!root) return 0;
	else
	{
		int lHeight = heightOfTree(root->left);
		int rHeight = heightOfTree(root->right);
		return max(lHeight,rHeight) + 1;
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

//自下而上的方法,在求树的深度的同时,对子树的平衡性进行判断
//因此,只需要一次深度优先遍历,就可以判断结束
//时间复杂度O(n)

//若子树已经不平衡了,直接返回-1
int dfsHeight (TreeNode *root) 
{
    if (root == NULL) return 0;
    
    int leftHeight = dfsHeight (root -> left);
    if (leftHeight == -1) return -1;
    int rightHeight = dfsHeight (root -> right);
    if (rightHeight == -1) return -1;
    
    if (abs(leftHeight - rightHeight) > 1)  return -1;
    return max (leftHeight, rightHeight) + 1;
}
    
bool isBalanced(TreeNode *root) 
{
	return dfsHeight (root) != -1;
}