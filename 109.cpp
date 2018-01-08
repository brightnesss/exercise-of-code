/*
 *	Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
 *	For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

 *	Example:
	Given the sorted linked list: [-10,-3,0,5,9],
	One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      	 0
     	/ \
      -3   9
   	  /   /
    -10  5
 */


ListNode* subSortedListToBST(ListNode* head, ListNode *&prehalf,ListNode *&posthalf)
{
	//mid是中间的数,prehalf是前一半最后一个数,posthalf是后一半第一个数
	if (!head) return NULL;
	ListNode *mid(head);
	prehalf = NULL;
	posthalf = head;
	while (posthalf->next&&posthalf->next->next)
	{
		prehalf = mid;
		mid = mid->next;
		posthalf = posthalf->next->next;
	}
	posthalf = mid->next;
	mid->next = NULL;
	if (prehalf) prehalf->next = NULL;
	return mid;
}

TreeNode* subSortedListToBST(ListNode* head)
{
	if (!head) return NULL;
	ListNode *prehalf(NULL), *posthalf(NULL), *mid(NULL);
	mid = subSortedListToBST(head, prehalf, posthalf);
	TreeNode *root = new TreeNode(mid->val);
	if (prehalf != NULL) root->left = subSortedListToBST(head);
	root->right = subSortedListToBST(posthalf);
	return root;
}

TreeNode* sortedListToBST(ListNode* head)
{
	//创建根结点
	if (!head) return NULL;
	ListNode *prehalf(NULL), *posthalf(NULL), *mid(NULL);
	mid = subSortedListToBST(head, prehalf, posthalf);
	TreeNode *root = new TreeNode(mid->val);
	if (prehalf != NULL) root->left = subSortedListToBST(head);	//若前一半最后一个数是NULL,说明前一半已经没有了,即head就是中间数mid
	root->right = subSortedListToBST(posthalf);
	return root;
}