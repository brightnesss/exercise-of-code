//leetcode No.563. Binary Tree Tilt 

/*	
 *	Given a binary tree, return the tilt of the whole tree.
 *	The tilt of a tree node is defined as the absolute difference between the sum of all left subtree node values and the sum of all right subtree node values. Null node has tilt 0.
 *	The tilt of the whole tree is defined as the sum of all nodes' tilt.
 */

int Tilt(TreeNode* root, int& sum)
{
	if (!root) return 0;
	int lchild = Tilt(root->left, sum);
	int rchild = Tilt(root->right, sum);
	sum += abs(lchild - rchild);
	return Tilt(root->left, sum) + Tilt(root->right, sum) + root->val;
}

int findTilt(TreeNode* root)
{
	int sum(0);
	Tilt(root, sum);
	return sum;
}