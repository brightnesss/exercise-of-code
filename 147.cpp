/*
 *	147. Insertion Sort List
 *	Sort a linked list using insertion sort.
 */

ListNode* insertionSortList(ListNode* head)
{
	ListNode *newHead = new ListNode(0);
	newHead->next = head;
	ListNode *cur(head), *pre(newHead), *tmp;
	while (head)
	{
		while (cur->next&&cur->next->val >= head->val) cur = cur->next;
		if (cur->next == NULL)
		{
			head = head->next;
			cur = head;
			continue;
		}
		while (pre->next&&pre->next->val <= cur->next->val) pre = pre->next;
		tmp = pre->next;
		pre->next = cur->next;
		cur->next = cur->next->next;
		pre->next->next = tmp;
		cur = head;
		pre = newHead;
	}
	return newHead->next;
}