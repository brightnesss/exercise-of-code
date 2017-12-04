/*
 *	24. Swap Nodes in Pairs
 *	Given a linked list, swap every two adjacent nodes and return its head.

 *	For example,
 *	Given 1->2->3->4, you should return the list as 2->1->4->3.
 *	Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
 */

ListNode* swapPairs(ListNode* head) 
{
    if (!head) return head;
    ListNode *newHead=new ListNode(0);
    newHead->next=head;
    ListNode *first(head), *second(head->next), *pre(newHead);
    while(first&&second)
    {
        first->next=second->next;
        second->next=first;
        pre->next=second;
        pre=first;
        first=first->next;
        second=first?first->next:NULL;
    }
    return newHead->next;
}