//leetcode No.230 Kth Smallest Element in a BST 

/*
 *	Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

 *	Note: 
 *	You may assume k is always valid, 1 ? k ? BST's total elements.

 *	Follow up:
 *	What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
 */


//中序遍历,因为BST中左子树<根<右子树
int kthSmallest(TreeNode* root, int k)
{
	stack<pair<TreeNode*, bool>> bin;
	bin.push(make_pair(root, false));
	while (!bin.empty())
	{
		pair<TreeNode*, bool> &tmp = bin.top();
		if (tmp.second)
		{
			if (0 == --k) return tmp.first->val;
			else
			{
				bin.pop();
				if (tmp.first->right) bin.push(make_pair(tmp.first->right, false));
			}
		}
		else
		{
			tmp.second = true;
			if (tmp.first->left) bin.push(make_pair(tmp.first->left, false));
		}
	}
}

int kthSmallest(TreeNode* root, int k)
{
	int cur(0);
	stack<pair<TreeNode*, bool>> tree;
	tree.push(make_pair(root, false));
	pair<TreeNode*,bool> top;
	while (!tree.empty())
	{
		top = tree.top();
		tree.pop();
		if (top.second)
		{
			cur += 1;
			if (cur == k) return top.first->val;
 		}
		else
		{
			if (top.first->right) tree.push(make_pair(top.first->right, false));
			top.second = true;
			tree.push(top);
			if (top.first->left) tree.push(make_pair(top.first->left, false));
		}
	}
}