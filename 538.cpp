//leetcode No.538 Convert BST to Greater Tree 

/*
 *	Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.
 *	Example: 
 *	Input: The root of a Binary Search Tree like this:
             5
           /   \
          2     13

 *	Output: The root of a Greater Tree like this:
             18
            /   \
          20     13
 */


//采用中序遍历的思想
//只不过一般的中序遍历是先遍历左孩子,后遍历右孩子
//该题先遍历右孩子,再遍历左孩子
TreeNode* convertBST(TreeNode* root)
{
	if (!root) return root;
	stack<pair<TreeNode*, bool>> bin;
	bin.push(make_pair(root, false));
	int count(0);
	while (!bin.empty())
	{
		pair<TreeNode*, bool> &tmp = bin.top();
		if (tmp.second)
		{
			tmp.first->val += count;
			count = tmp.first->val;
			bin.pop();
			if (tmp.first->left) bin.push(make_pair(tmp.first->left,false));
		}
		else
		{
			tmp.second = true;
			if (tmp.first->right) bin.push(make_pair(tmp.first->right, false));
		}
	}
	return root;
}