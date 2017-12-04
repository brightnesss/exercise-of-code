/*
 *	92. Reverse Linked List II
 *	Reverse a linked list from position m to n. Do it in-place and in one-pass.

 *	For example:
 *	Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 *	return 1->4->3->2->5->NULL.

 *	Note:
 *	Given m, n satisfy the following condition:
 *	1 ≤ m ≤ n ≤ length of list.
 */

ListNode* reverseBetween_92(ListNode* head, int m, int n)
{
	ListNode *newHead = new ListNode(0);
	newHead->next = head;
	ListNode *pre(newHead), *next;
	for (int i = 1;i != m;++i)
	{
		//先走到开始的位置m
		head = head->next;
		pre = pre->next;
	}
	for (int i = m;i != n;++i)
	{
		//从m开始,到n为止
		next = head->next;
		head->next = next->next;
		next->next = head;
		pre->next = next;
	}
	return newHead->next;
}