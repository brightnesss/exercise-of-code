//leetcode No.234 Palindrome Linked List 

/*
 *	Given a singly linked list, determine if it is a palindrome.
 *	Follow up:
 *	Could you do it in O(n) time and O(1) space?
 */

bool isPalindrome(ListNode* head)
{
	if (!head) return true;
	ListNode *slow = head, *fast = head;
	int count(1);
	while (fast->next && fast->next->next)
	{
		slow = slow->next;
		fast = fast->next;
		++count;
	}
	if (count == 1) return true;
	if (!fast->next) --count;
	slow = slow->next;
	ListNode *pre = NULL, *next;
	while (slow)
	{
		next = slow->next;
		slow->next = pre;
		pre = slow;
		slow = next;
	}

	ListNode* head2 = pre;
	for (int i = 0;i < count;++i)
	{
		if (head2->val == head->val)
		{
			head2 = head2->next;
			head = head->next;
		}
		else return false;
	}
	return true;
}