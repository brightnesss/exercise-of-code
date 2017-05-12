//leetcode No.203 Remove Linked List Elements 

/*
 *	Remove all elements from a linked list of integers that have value val.
 *	Example
 *	Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
 *	Return: 1 --> 2 --> 3 --> 4 --> 5 
 */


ListNode* removeElements(ListNode* head, int val)
{
	while (head && head->val == val) head = head->next;
	if (!head) return head;
	ListNode* next = head;
	while (next->next)
	{
		if (next->next->val == val) next->next = next->next->next;
		else next = next->next;
	}
	return head;
}