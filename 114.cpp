/*
 *	114. Flatten Binary Tree to Linked List
 *	Given a binary tree, flatten it to a linked list in-place.

 *	For example,
 *	Given

         1
        / \
       2   5
      / \   \
     3   4   6
 *	The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
 */

/*
 *	1)找到左子树的最右端的叶子结点
 *	2)它的右子树为根节点的右子树
 *	3)而根节点的右子树为左子树,左子树为NULL
 *	4)使根节点下移(移动到根节点的右子树),重复1)
 */

void flatten(TreeNode* root)
{
	if (!root) return;
	TreeNode *head(root);
	while (head->left || head->right)
	{
		if (head->left)	//若左子树存在
		{
			TreeNode* leftright = head->left;
			while (leftright->right || leftright->left)	//找到左子树的最右端叶子结点
			{
				if (leftright->right) leftright = leftright->right;
				else if (leftright->left) leftright = leftright->left;
			}
			leftright->right = head->right;	//该结点的右子树为根的右子树
			head->right = head->left;	//根的右子树为左子树
			head->left = NULL;	//根的左子树为NULL
		}
		head = head->right;
	}
}