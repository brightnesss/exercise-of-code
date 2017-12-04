/*
 *	143. Reorder List
 *	Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 *	reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 *	You must do this in-place without altering the nodes' values.

 *	For example,
 *	Given {1,2,3,4}, reorder it to {1,4,2,3}.
 */

/*
 *	基本思路就是将L的后半段逆序,得到Ln->Ln-1->Ln-2->...->Ln/2
 *	然后与前半段合并L0->L1->...->L(n/2)-1进行一一合并
 */

ListNode* reverseList(ListNode* head) 
{
	if (!head) return head;
	ListNode *newHead = new ListNode(0), *cur(head), *next(cur->next);
	newHead->next = head;
	while (cur->next)
	{
		cur->next = next->next;
		next->next = newHead->next;
		newHead->next = next;
		next = cur->next;
	}
	return newHead->next;
}

void reorderList(ListNode* head)
{
	int len(0);
	ListNode *slow(head);
	while (slow)
	{
		++len;
		slow = slow->next;
	}
	if (len <= 2) return;
	ListNode *fast(head->next);
	slow = head;
	if (len % 2 == 0)
	{
		while (fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		slow = slow->next;
		ListNode *secondHead = reverseList(slow);
		slow = head;
		fast = secondHead;
		while (fast)
		{
			ListNode *slowtmp, *fasttmp;
			slowtmp = slow->next;
			fasttmp = fast->next;
			slow->next = fast;
			fast->next = slowtmp;
			slow = slowtmp;
			fast = fasttmp;
		}
		slow->next = NULL;
	}
	else
	{
		while (fast->next->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		slow = slow->next->next;
		ListNode *secondHead = reverseList(slow);
		slow = head;
		fast = secondHead;
		while (fast)
		{
			ListNode *slowtmp, *fasttmp;
			slowtmp = slow->next;
			fasttmp = fast->next;
			slow->next = fast;
			fast->next = slowtmp;
			slow = slowtmp;
			fast = fasttmp;
		}
		slow->next = NULL;
	}
}