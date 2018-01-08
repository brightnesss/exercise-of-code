/*
 *	124. Binary Tree Maximum Path Sum
 *	Given a binary tree, find the maximum path sum.
 *	For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. 
 *	The path must contain at least one node and does not need to go through the root.

 *	For example:
 *	Given the below binary tree,

       1
      / \
     2   3

 *	Return 6.
 */

/*
 *	用maxNum来标记当前找到的最大值,相当于一个全局量
 *	在每一个根节点root的位置上:
 		1)以它为转折点,能达到的最大值为它的值+它左子树的值+它右子树的值
 		2)但当他要向上传递值时,只能传递一个枝的值,即要么为它的值+它左子树的值,或者为它的值+它右子树的值
 *	对于每一个子树传递上来的值,令其最小为0,否则就没有加的意义
 */

int subMaxPathSum(TreeNode* root, int &maxNum)
{
	if (!root) return 0;
	int left = subMaxPathSum(root->left, maxNum);
	int right = subMaxPathSum(root->right, maxNum);
	int tmp(0);	//子树中传递的值最小为0

	/*
	 *	遍历所有三种情况,找到它的最大值
	 *	即要么就是root
	 *	要么是root+左子树
	 *	要么是root+右子树
	 */
	tmp = max(tmp, root->val);	
	tmp = max(tmp, root->val + left);
	tmp = max(tmp, root->val + right);

	//当前最大的值和该root结点上能达到的最大值比较
	maxNum = max(maxNum, root->val + left + right);	//因为left和right最小为0,所以可以直接这样计算
	return tmp;
}

int maxPathSum(TreeNode* root)
{
	if (!root) return 0;
	int maxNum(INT_MIN);
	subMaxPathSum(root, maxNum);
	return maxNum;
}