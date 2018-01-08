/*
 *	98. Validate Binary Search Tree
 *	Given a binary tree, determine if it is a valid binary search tree (BST).
 *	Assume a BST is defined as follows:
 *	The left subtree of a node contains only nodes with keys less than the node's key.
 *	The right subtree of a node contains only nodes with keys greater than the node's key.
 *	Both the left and right subtrees must also be binary search trees.

 *	Example 1:
    2
   / \
  1   3
	Binary tree [2,1,3], return true.

 *	Example 2:
    1
   / \
  2   3
	Binary tree [1,2,3], return false.
 */

/*
 *	非常暴力的方法,在每一个结点都判断是不是BST
 */
bool subLeftIsValidBst(TreeNode* root, int val)
{
	if (!root) return true;
	queue<TreeNode*> bin;
	bin.push(root);
	TreeNode* front;
	while (!bin.empty())
	{
		front = bin.front();
		bin.pop();
		if (front->val >= val) return false;
		if (front->left) bin.push(front->left);
		if (front->right) bin.push(front->right);
	}
	return true;
}

bool subRightIsValidBst(TreeNode* root, int val)
{
	if (!root) return true;
	queue<TreeNode*> bin;
	bin.push(root);
	TreeNode* front;
	while (!bin.empty())
	{
		front = bin.front();
		bin.pop();
		if (front->val <= val) return false;
		if (front->left) bin.push(front->left);
		if (front->right) bin.push(front->right);
	}
	return true;
}

bool isValidBST(TreeNode* root)
{
	if (!root) return true;
	queue<TreeNode*> bin;
	bin.push(root);
	TreeNode* front;
	while (!bin.empty())
	{
		front = bin.front();
		bin.pop();
		if (subLeftIsValidBst(front->left, front->val) && subRightIsValidBst(front->right, front->val))
		{
			if (front->left) bin.push(front->left);
			if (front->right) bin.push(front->right);
		}
		else return false;
	}
	return true;
}

/*
 *	一颗BST通过中序遍历可以展开成一个递增的数列
 *	可以通过此来判断是不是一个BST
 */