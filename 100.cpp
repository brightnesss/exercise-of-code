/*
 *	100. Same Tree
 *	Given two binary trees, write a function to check if they are the same or not.
 *	Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

 *	Example 1:

	Input:     1         1
    	      / \       / \
        	 2   3     2   3

        	[1,2,3],   [1,2,3]

	Output: true

 *	Example 2:

	Input:     1         1
    	      /           \
        	 2             2

        	[1,2],     [1,null,2]

	Output: false

 *	Example 3:

	Input:     1         1
    	      / \       / \
        	 2   1     1   2

        	[1,2,1],   [1,1,2]

	Output: false
 */

/*
 *	既要判断是否每一个结点相等,也要判断结构是否相同
 *	广度优先搜索
 */

bool isSameTree(TreeNode* p, TreeNode* q)
{
	if (p == NULL&&q == NULL) return true;
	if (!(p&&q&&p->val == q->val)) return false;
	queue<TreeNode*> tree1, tree2;
	tree1.push(p);
	tree2.push(q);
	TreeNode* front1, *front2;
	while (!(tree1.empty() && tree2.empty()))
	{
		front1 = tree1.front();
		front2 = tree2.front();
		tree1.pop();
		tree2.pop();
		if (front1->val == front2->val)
		{
			if (front1->left != NULL&&front2->left != NULL)
			{
				tree1.push(front1->left);
				tree2.push(front2->left);
			}
			else if (front1->left == NULL&&front2->left == NULL);
			else return false;

			if (front1->right != NULL&&front2->right != NULL)
			{
				tree1.push(front1->right);
				tree2.push(front2->right);
			}
			else if (front1->right == NULL&&front2->right == NULL);
			else return false;
		}
		else return false;
	}
	return true;
}