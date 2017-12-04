/*
 *	61. Rotate List
 *	Given a list, rotate the list to the right by k places, where k is non-negative.

 *	Example:
 *	Given 1->2->3->4->5->NULL and k = 2,
 *	return 4->5->1->2->3->NULL.
 */

ListNode* rotateRight(ListNode* head, int k)
{
	ListNode *newHead = new ListNode(0);
	newHead->next = head;
	ListNode *slow(newHead), *fast(newHead), *count(newHead);
	int cnt(0);
	while (count->next)
	{
		++cnt;
		count = count->next;
	}
	if (cnt == 0) return head;
	k %= cnt;
	for (int i = 0;i != k;++i) fast = fast->next;
	while (fast->next)
	{
		slow = slow->next;
		fast = fast->next;
	}
	fast->next = head;
	newHead->next = slow->next;
	slow->next = NULL;
	return newHead->next;
}