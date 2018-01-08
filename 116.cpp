
/*
 *	116. Populating Next Right Pointers in Each Node
 *	Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }

 *	Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
 *	Initially, all next pointers are set to NULL.

 *	Note:
 *	You may only use constant extra space.
 *	You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).

 *	For example,
 *	Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7

 *	After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
 */



void subConnect(TreeLinkNode *root)
{
	if (root->left)	//因为是完全二叉树,只要下一层存在一个结点,则这一层都是存在的
	{
		root->left->next = root->right;	//先将根的两个子树连起来
		TreeLinkNode *left(root->left), *right(root->right);
		while (left->right)
		{
			//从根以下,所有的分叉的地方都连起来,即左子树的所有右子结点和右子树的所有左子结点
			left->right->next = right->left;
			left = left->right;
			right = right->left;
		}
		//递归
		subConnect(root->left);
		subConnect(root->right);
	}
	else return;
}

void connect(TreeLinkNode *root)
{
	if (!root) return;
	subConnect(root);
}


/*
 *	先找到每一层的第一个结点,利用该层已经连起来的先验条件,通过next来不断遍历该层,实现了BFS
 */
void connect(TreeLinkNode *root) 
{
    if (root == NULL) return;
    TreeLinkNode *pre = root;
    TreeLinkNode *cur = NULL;
    while(pre->left) 
    {
        cur = pre;
        while(cur) {
            cur->left->next = cur->right;
            if(cur->next) cur->right->next = cur->next->left;
            cur = cur->next;
        }
        pre = pre->left;
    }
}