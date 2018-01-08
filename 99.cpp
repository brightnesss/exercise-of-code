/*
 *	99. Recover Binary Search Tree
 *	Two elements of a binary search tree (BST) are swapped by mistake.
 *	Recover the tree without changing its structure.

 *	Note:
 *	A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
 */

/*
 *	一个二叉搜索树中序遍历展开后应该是有序数列
 *	应用这一点,将二叉搜索树中序遍历展开,对值排序后再赋值
 */

void recoverTree(TreeNode* root)
{
	if (!root) return;
	stack<pair<TreeNode*,bool>> bin;
	bin.push(make_pair(root, false));
	vector<TreeNode*> vecT;
	vector<int> vecI;
	pair<TreeNode*, bool> top;
	while (!bin.empty())
	{
		top = bin.top();
		bin.pop();
		if (top.second)
		{
			vecT.push_back(top.first);
			vecI.push_back(top.first->val);
		}
		else
		{
			if (top.first->right) bin.push(make_pair(top.first->right, false));
			top.second = true;
			bin.push(top);
			if (top.first->left) bin.push(make_pair(top.first->left, false));
		}
	}
	sort(vecI.begin(), vecI.end());
	for (int i = 0;i != vecI.size();++i) vecT[i]->val = vecI[i];
	return;
}