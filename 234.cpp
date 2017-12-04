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

/*
 *	翻转后一半的list,然后和前一半进行比较,若都相同,则说明是回文,否则不是
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

bool isPalindrome(ListNode* head)
{
	if (!(head&&head->next)) return true;
	ListNode *slow(head), *fast(head);
	while (fast->next&&fast->next->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	slow->next = reverseList(slow->next);
	fast = slow->next, slow = head;
	while (fast)
	{
		if (slow->val == fast->val)
		{
			slow = slow->next;
			fast = fast->next;
		}
		else return false;
	}
	return true;
}