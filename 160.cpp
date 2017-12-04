/*
 *	160. Intersection of Two Linked Lists

 *	Write a program to find the node at which the intersection of two singly linked lists begins.

 *	For example, the following two linked lists:

 	A:          a1 → a2
 	                  ↘
    	                 c1 → c2 → c3
        	           ↗            
	B:     b1 → b2 → b3
 	begin to intersect at node c1.

 *	Notes:
 *	If the two linked lists have no intersection at all, return null.
 *	The linked lists must retain their original structure after the function returns.
 *	You may assume there are no cycles anywhere in the entire linked structure.
 *	Your code should preferably run in O(n) time and use only O(1) memory.
 */

/*
 *	先将两个list的长度平齐,然后从头开始找,直到找到相同的那一个(相同的必定存在,至少同为尾部的NULL)
 */
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
	ListNode *a(headA), *b(headB);
	int lenA(0), lenB(0);
	while (a)
	{
		++lenA;
		a = a->next;
	}
	while (b)
	{
		++lenB;
		b = b->next;
	}
	a = headA;
	b = headB;
	if (lenA > lenB)
	{
		int diff = lenA - lenB;
		for (int i = 0;i != diff;++i) a = a->next;
	}
	else
	{
		int diff = lenB - lenA;
		for (int i = 0;i != diff;++i) b = b->next;
	}
	while (a != b)
	{
		a = a->next;
		b = b->next;
	}
	return a;
}