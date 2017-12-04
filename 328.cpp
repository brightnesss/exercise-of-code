//leetcode No.328 Odd Even Linked List 

/*
 *	Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.
 *	You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

 *	Example:
 *	Given 1->2->3->4->5->NULL,
 *	return 1->3->5->2->4->NULL. 

 *	Note:
 *	The relative order inside both the even and odd groups should remain as it was in the input. 
 *	The first node is considered odd, the second node even and so on ... 
 */

/*	用两个指针分别指向奇数结点和偶数结点
 *	需要考虑三种边界情况
 *	1.链表为空或链表只有一个头节点
 *	2.链表总共有偶数个结点
 *	3.链表总共有奇数个结点(不包括只有头节点的情况)
 */

ListNode* oddEvenList(ListNode* head)
{
	if (head == NULL || head->next == NULL) return head;
	ListNode *headeven = head->next;
	ListNode *tmpodd = head, *tmpeven = headeven;
	while (tmpodd && tmpeven)
	{
		if (tmpeven->next)
		{
			tmpodd->next = tmpeven->next;
			tmpodd = tmpodd->next;
		}
		else tmpodd->next = tmpeven->next;
		tmpeven->next = tmpodd ? tmpodd->next : NULL;
		tmpeven = tmpeven->next;
	}
	tmpodd->next = headeven;
	return head;
}

// a better one
 ListNode* oddEvenList(ListNode* head) 
{
    if(!head) return head;
    ListNode *odd=head, *evenhead=head->next, *even = evenhead;
    while(even && even->next)
    {
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = evenhead;
    return head;
}

ListNode* oddEvenList(ListNode* head)
{
	ListNode *oddHead, *evenHead;
	if (head) oddHead = head;
	else return head;
	if (head->next) evenHead = head->next;
	else return head;
	head = evenHead->next;
	ListNode *odd(oddHead), *even(evenHead);
	bool isOdd(true);
	while (head)
	{
		if (isOdd)
		{
			odd->next = head;
			odd = odd->next;
			isOdd = false;
		}
		else
		{
			even->next = head;
			even = even->next;
			isOdd = true;
		}
		head = head->next;
	}
	odd->next = evenHead;
	even->next = NULL;
	return oddHead;
}