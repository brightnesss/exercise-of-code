/*
 *	129. Sum Root to Leaf Numbers
 *	Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
 *	An example is the root-to-leaf path 1->2->3 which represents the number 123.
 *	Find the total sum of all root-to-leaf numbers.

 *	For example,

    1
   / \
  2   3

 *	The root-to-leaf path 1->2 represents the number 12.
 *	The root-to-leaf path 1->3 represents the number 13.

 *	Return the sum = 12 + 13 = 25.
 */

/*
 *	通过每一个结点的val将所有的值传递下去,直到叶子节点
 *	在叶子节点上,将值加起来
 *	传递的方法就是root的val*10分别加上左右子树的val
 *	缺点是改变了每一个结点上的val
 */

int sumNumbers(TreeNode* root)
{
	if (!root) return 0;
	queue<TreeNode*> q;
	TreeNode *front;
	q.push(root);
	int ans(0);
	while (!q.empty())
	{
		int len = q.size();
		for (int i = 0;i != len;++i)
		{
			front = q.front();
			q.pop();
			if (front->left == NULL&&front->right == NULL) ans += front->val;
			if (front->left)
			{
				front->left->val += 10 * front->val;
				q.push(front->left);
			}
			if (front->right)
			{
				front->right->val += 10 * front->val;
				q.push(front->right);
			}
		}
	}
	return ans;
}

/*
 *	通过递归使用DFS,来完成
 *	没有改变结点的val
 */

int subSumNumbers(TreeNode* root, int val)
{
	if (root->left==NULL&&root->right==NULL) return 10 * val + root->val;
	int subval(0);
	if (root->left) subval+=subSumNumbers(root->left, 10 * val + root->val);
	if (root->right) subval+=subSumNumbers(root->right, 10 * val + root->val);
	return subval;
}

int sumNumbers(TreeNode* root)
{
	if (!root) return 0;
	return subSumNumbers(root, 0);
}