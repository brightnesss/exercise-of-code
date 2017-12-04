/*
 *	86. Partition List
 *	Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
 *	You should preserve the original relative order of the nodes in each of the two partitions.

 *	For example,
 *	Given 1->4->3->2->5->2 and x = 3,
 *	return 1->2->2->4->3->5.
 */

/*
 *	用两个队列分别存储小于x的结点和大于x的结点
 *	后面在分别把小的和大的串联起来
 *	使用队列(FIFO)可以保证相互的顺序,而使用两个队列可以保证大小关系不变
 */
ListNode* partition(ListNode* head, int x)
{
	if (!head) return head;
	queue<ListNode*> low, high;
	while (head)
	{
		if (head->val < x) low.push(head);
		else high.push(head);
		head = head->next;
	}
	ListNode *newHead, *tmp;
	if (!low.empty())
	{
		newHead = tmp = low.front();
		low.pop();
		while (!low.empty())
		{
			tmp->next = low.front();
			tmp = tmp->next;
			low.pop();
		}
		while (!high.empty())
		{
			tmp->next = high.front();
			tmp = tmp->next;
			high.pop();
		}
	}
	else
	{
		newHead = tmp = high.front();
		high.pop();
		while (!high.empty())
		{
			tmp->next = high.front();
			tmp = tmp->next;
			high.pop();
		}
	}
	tmp->next = NULL;
	return newHead;
}

/*
 *	思路不变
 *	但其实不需要使用队列也可以,只需要用两个链表来串接起来就好了	
 *	用一队链表来表示小于x的node,一队链表来表示大于x的node
 *	在结尾处只要把两个链表连接起来就好
 */

ListNode* partition(ListNode* head, int x)
{
	ListNode *low = new ListNode(0);
	ListNode *high = new ListNode(0);
	ListNode *newHead(low),*tmp(high);
	while(head)
	{
		if (head->val<x) 
		{
			low->next=head;
			low=low->next;
		}
		else
		{
			high->next=head;
			high=high->next;
		}
		head=head->next;
	}
	high->next=NULL;
	low->next=tmp->next;
	return newHead->next;
}