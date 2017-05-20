//leetcode No.141 Linked List Cycle 

/*
 *	Given a linked list, determine if it has a cycle in it. 
 *	Follow up:
 *	Can you solve it without using extra space? 
 */

bool hasCycle(ListNode *head)
{
	//一个指针一次走两步，另一个一次走一步
	//若有环，则走得快的势必会追上走得慢的
	
	if (!head) return false;
	ListNode *q = head, *s = head;
	while (q->next && q->next->next)
	{
		q = q->next->next;
		s = s->next;
		if (q == s) return true;
	}
	return false;
}