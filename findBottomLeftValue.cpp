//leetcode No.513 Find Bottom Left Tree Value 

/*
 *	Given a binary tree, find the leftmost value in the last row of the tree. 

 *	Example:
 *	Input:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

 *	Output:
 	7

 */

//找最深层最左边的结点
int leftvalue(TreeNode* root, int &ans)
{
	//若层深相同，返回左结点
	//否则返回层深大的结点
	if (!root) return 0;
	else
	{
		ans = root->val;
		int heightl = leftvalue(root->left, ans);
		int heightlv = ans;
		int heightr = leftvalue(root->right, ans);
		int heightrv = ans;
		if (heightl >= heightr)
		{
			ans = heightlv;
			return 1 + heightl;
		}
		else
		{
			ans = heightrv;
			return 1 + heightr;
		}
	}
}

int findBottomLeftValue(TreeNode* root)
{
	int ans = root->val;
	leftvalue(root, ans);
	return ans;
}