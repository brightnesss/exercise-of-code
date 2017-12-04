/* 
 *	19. Remove Nth Node From End of List
 *	Given a linked list, remove the nth node from the end of list and return its head.

 *	For example,
 *	Given linked list: 1->2->3->4->5, and n = 2.
 *	After removing the second node from the end, the linked list becomes 1->2->3->5.

 *	Note:
 *	Given n will always be valid.
 *	Try to do this in one pass.
 */


/*
 *	使用快慢指针,快指针比慢指针多n
 *	则当快指针指向NULL(即list的末尾)时,慢指针指向该删除的数
 *	同时还需要一个pre来表示慢指针前一个数
 */
ListNode* removeNthFromEnd(ListNode* head, int n)
{
	ListNode *slow(head), *fast(head), *pre(NULL);
	for (int i = 0;i != n;++i) fast = fast->next;
	while (fast)
	{
		pre = slow;
		slow = slow->next;
		fast = fast->next;
	}
	if (pre == NULL) return head = head->next;	//说明需要删除的是头指针
	else
	{
		pre->next = slow->next;
	}
	return head;
}