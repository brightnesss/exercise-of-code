/*
 *	82. Remove Duplicates from Sorted List II
 *	Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

 *	For example
 *	Given 1->2->3->3->4->4->5, return 1->2->5.
 *	Given 1->1->1->2->3, return 2->3.
 */

/*
 *	时间复杂度O(n),空间复杂度O(1)
 *	head来表示当前遍历到的node,pre表示head之前的那个node

 *	当head->val==head->next->val时,用next来表示head之后的某一个node,一直搜索到head->val!=next->val,则next表示第一个与head->val不等的数
 *	此时只需要将pre直接指向next,就将pre和next之间所有相等的node都删除了
 *	若head->val!=head->next->val,则只需要让head继续遍历,同时pre也向前一步
 */
ListNode* deleteDuplicates_82(ListNode* head)
{
	ListNode *newHead = new ListNode(0);
	newHead->next = head;
	ListNode *pre(newHead), *next;
	while (head&&head->next)
	{
		if (head->val == head->next->val)
		{
			next = head->next;
			while (next&&head->val == next->val)
			{
				next = next->next;
			}
			pre->next = next;
			head = next;
		}
		else
		{
			head = head->next;
			pre = pre->next;
		}
	}
	return newHead->next;
}