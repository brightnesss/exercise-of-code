/*
 *	148. Sort List
 *	Sort a linked list in O(n log n) time using constant space complexity.
 */	

/*
 *	使用归并排序,之前确实还不太了解归并排序,是一种O(nlogn)的排序方法,空间复杂度一般是O(n)
 *	在这里,使用递归的方法进行
 *	每次,将list分为两段,对每一段进行排序,然后进行归并
 */

ListNode* getMid(ListNode* head)
{
	//为了将list分为两段,需要用快慢指针,同时需要注意要将前一段的尾巴封住,即slow->next=NULL
	ListNode *slow(head), *fast(head);
	while (fast->next&&fast->next->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	fast = slow->next;
	slow->next = NULL;
	return fast;
}

ListNode* merge(ListNode* l1, ListNode*l2)
{
	//进行merge
	//思路是用l1中的每一个数和l2中的每一个数逐个比较
	//最后将尾巴封住
	ListNode *newHead = new ListNode(0);
	ListNode *tmp(newHead);
	while (l1&&l2)
	{
		if (l1->val < l2->val)
		{
			tmp->next = l1;
			l1 = l1->next;
		}
		else
		{
			tmp->next = l2;
			l2 = l2->next;
		}
		tmp = tmp->next;
	}
	while (l1)
	{
		tmp->next = l1;
		l1 = l1->next;
		tmp = tmp->next;
	}
	while (l2)
	{
		tmp->next = l2;
		tmp = tmp->next;
		l2 = l2->next;
	}
	tmp->next = NULL;
	return newHead->next;
}

ListNode* sortList(ListNode* head)
{
	//递归,递归结束的条件是list中只有一个node甚至list为空
	if (!(head&&head->next)) return head;
	ListNode *l1(head), *l2 = getMid(head);
	l1 = sortList(l1);
	l2 = sortList(l2);
	return merge(l1, l2);
}