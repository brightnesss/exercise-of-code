/*
 *	2. Add Two Numbers
 *	You are given two non-empty linked lists representing two non-negative integers. 
 *	The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

 *	You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 *	Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 *	Output: 7 -> 0 -> 8
 */

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	int jinwei(0);
	ListNode *head(l1), *pre(NULL);
	while (l1&&l2)
	{
		l1->val += l2->val + jinwei;
		jinwei = 0;
		if (l1->val >= 10)
		{
			l1->val -= 10;
			jinwei = 1;
		}
		pre = l1;
		l1 = l1->next;
		l2 = l2->next;
	}
	while (l1)
	{
		l1->val += jinwei;
		jinwei = 0;
		if (l1->val >= 10)
		{
			l1->val -= 10;
			jinwei = 1;
		}
		pre = l1;
		l1 = l1->next;
	}
	while (l2)
	{
		pre->next = l2;
		l2->val += jinwei;
		jinwei = 0;
		if (l2->val >= 10)
		{
			l2->val -= 10;
			jinwei = 1;
		}
		pre = pre->next;
		l2 = l2->next;
	}
	if (jinwei)
	{
		pre->next = new ListNode(1);
	}
	return head;
}