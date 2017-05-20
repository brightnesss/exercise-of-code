//leetcode No.530. Minimum Absolute Difference in BST 

/*
 *	Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes
 *	Example: 
 *	Input:

 *	  1
 *	   \
 *	    3
 *	   /
 *	  2

 *	Output:
 *	1

 *	Explanation:
 *	The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
 */


//相差最小的肯定是左子树的右子树
//或者右子树的左子树
void minimumDifference(TreeNode* root, int& minNum)
{
	if (!root) return;
	TreeNode* lchildrchild, *rchildlchild;
	int lchild = INT32_MAX, rchild = INT32_MAX;
	if (root->left)
	{
		lchildrchild = root->left;
		while (lchildrchild->right) lchildrchild = lchildrchild->right;
		lchild = abs(root->val - lchildrchild->val);
	}
	if (root->right)
	{
		rchildlchild = root->right;
		while (rchildlchild->left) rchildlchild = rchildlchild->left;
		rchild = abs(root->val - rchildlchild->val);
	}
	minNum = min(minNum, min(lchild, rchild));
	minimumDifference(root->left, minNum);
	minimumDifference(root->right, minNum);
}

int getMinimumDifference(TreeNode* root)
{
	int minNum = INT32_MAX;
	minimumDifference(root, minNum);
	return minNum;
}