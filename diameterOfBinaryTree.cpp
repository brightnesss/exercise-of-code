// leetcode No.543 Diameter of Binary Tree 

#include "includelib.h"

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int findDiameter(TreeNode* root, int &max)
{
	/*
	 *	利用查找树的深度的算法，再加上一个max用来记root结点的两个子树中最大的直径
	 *	在root节点中通过比较【max，左子树深度+右子树深度】来更新max的值
	 */
	int deep(0);
	if (root)
	{
		int leftChildren = findDiameter(root->left, max);
		int rightChildren = findDiameter(root->right, max);
		deep = leftChildren >= rightChildren ? leftChildren + 1 : rightChildren + 1;
		max = max > leftChildren + rightChildren ? max : leftChildren + rightChildren;
	}
	return deep;
}

int diameterOfBinaryTree(TreeNode* root)
{
	// maxDiameter用来记最大直径
	int maxDiameter(0);
	findDiameter(root, maxDiameter);
	return maxDiameter;
}