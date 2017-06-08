//leetcode No.337 House Robber III 

/*
 *	The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night. 
 *	Determine the maximum amount of money the thief can rob tonight without alerting the police. 
 *	Example 1:
	     3
	    / \
	   2   3
	    \   \ 
	     3   1
 *	Maximum amount of money the thief can rob = 3 + 3 + 1 = 7. 

 *	Example 2:
	     3
	    / \
	   4   5
	  / \   \ 
	 1   3   1
 *	Maximum amount of money the thief can rob = 4 + 5 = 9. 
 */


//分两种情况,抢这个结点还是不抢这个结点
//抢的话,就只能抢子节点的子节点
int rob(TreeNode* root)
{
	if (!root) return 0;
	int robthis(0), notrobthis(0);
	robthis = root->val;
	if (root->left)
	{
		notrobthis += rob(root->left);
		robthis += rob(root->left->left) + rob(root->left->right);
	}
	if (root->right)
	{
		notrobthis += rob(root->right);
		robthis += rob(root->right->left) + rob(root->right->right);
	}
	return max(robthis, notrobthis);
}