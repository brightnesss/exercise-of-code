/*
 *	117. Populating Next Right Pointers in Each Node II
 *	Follow up for problem "Populating Next Right Pointers in Each Node".
 *	What if the given tree could be any binary tree? Would your previous solution still work?

 *	Note:
 *	You may only use constant extra space.

 *	For example,
 *	Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7

 *	After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL

 */

/*
 *	参考116题的结果,但因为116是完全二叉树,可以保证每一层都是满的,所以在这一点上需要修改
 */

void connect_116(TreeLinkNode *root) 
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

/*
 *	在116的基础上修改
 		1)首先要找到第一个含有子节点的root,116题中如果含有子节点,则目前层的第一个结点肯定含有左子结点,在117中这一点不成立
 		2)使用last指针来指向该层需要进行连接的结点,若cur是当前层第一个有子节点的结点,则last必定是cur的结点中的一个,若没有右子节点,last=左子结点,若有右子节点,last=右子节点
 		3)
 */

void connect_117(TreeLinkNode *root)
{
	if (!root) return;
	TreeLinkNode *pre(root), *cur(NULL), *last(NULL);
	while (pre)
	{
		if (pre->left || pre->right)	//如果含有子节点
		{
			last = NULL;
			cur = pre;
			if (pre->left) pre = pre->left;
			else pre = pre->right;
			while (cur)
			{
				if (cur->left == NULL&&cur->right == NULL)	//如果cur没有子节点,那也不需要连接,直接进入cur->next
				{
					cur = cur->next;
					continue;
				}
				if (cur->left)
				{
					if (last != NULL) last->next = cur->left;	//若last存在,说明last需要连接,则last->next=cur->left
					last = cur->left;	//不论last是否存在,需要连接的结点都是cur->left
				}
				if (cur->right)
				{
					if (last!=NULL) last->next = cur->right;	//last存在,说明last需要连接,则last->next=cur->right
					last = cur->right;	//不论last是否存在,需要连接的结点都是cur->right
				}
				cur = cur->next;	//更新cur
			}
		}
		else pre = pre->next;	//若不含有子节点,就遍历他的邻接结点(同一层)
	}
}