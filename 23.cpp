/*
 *	23. Merge k Sorted Lists
 *	Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 */



/*
 *	时间复杂度是O(k*Max(len(lists)))
 *	即k*lists中最长的一个链表的长度
 *	基本思路就是每次比较lists中的node,将最小的取出,同时将最小的node=node->next
 *	这个方法可以用最小堆来优化,应该可以使得速度从O(k*max)变为O(logk*max)
 */
ListNode* subMergeKLists(vector<ListNode*>& lists, const int len)
{
	if (len < 1) return NULL;
	int num(INT_MAX), index(0);
	for (int i = 0;i != len;++i)
	{
		if (lists[i] == NULL) continue;
		if (lists[i]->val < num)
		{
			num = lists[i]->val;
			index = i;
		}
	}
	ListNode *ans(lists[index]);
	if (ans!=NULL) lists[index] = lists[index]->next;
	return ans;
}

ListNode* mergeKLists(vector<ListNode*>& lists)
{
	int len(lists.size());
	ListNode *head = new ListNode(0);
	ListNode *next(head), *tmp;
	while (tmp = subMergeKLists(lists, len))
	{
		next->next = tmp;
		next = next->next;
	}
	return head->next;
}