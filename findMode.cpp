//leetcode No.501 Find Mode in Binary Search Tree 

/*
 *	Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.
 *	Assume a BST is defined as follows: 
 *	The left subtree of a node contains only nodes with keys less than or equal to the node's key.
 *	The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
 *	Both the left and right subtrees must also be binary search trees.
 */

int Mode(TreeNode* root, int mode)
{
	//计算当前mode出现了几次
	if (!root) return 0;
	if (root->val < mode) return 0 + Mode(root->right, mode); //当前结点值比mode小，则只有root的右子树的值可能和mode相同(因为这是BST)
	else if (root->val > mode) return 0 + Mode(root->left, mode); //同上
	else
	{
		return 1 + Mode(root->left, mode) + Mode(root->right, mode); //相等则左右子树都可能
	}
}

void isMode(TreeNode* root, vector<int> &ans, int &Current)
{
	//计算当前root的值是不是一个mode
	//Current表示mode的出现次数
	if (!root) return;
	int tmp = Mode(root->left, root->val) + Mode(root->right, root->val) + 1;
	if (tmp == Current) ans.push_back(root->val); //如果root值是mode，就放到ans中
	else if (tmp > Current)
	{
		//若root值比之前mode的出现次数多，则之前的mode就不是mode了，清空之前的记录，并更新current
		Current = tmp;
		ans.clear();
		ans.push_back(root->val);
	}
	//递归调用
	isMode(root->left, ans, Current);
	isMode(root->right, ans, Current);
}

vector<int> findMode(TreeNode* root)
{
	int current(0);
	vector<int> ans;
	if (!root) return ans;
	else
	{
		isMode(root, ans, current);
	}
	return ans;
}