/* 
 *	25. Reverse Nodes in k-Group

 *	Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 *	k is a positive integer and is less than or equal to the length of the linked list. 
 *	If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
 *	You may not alter the values in the nodes, only nodes itself may be changed.
 *	Only constant memory is allowed.

 *	For example,
 *	Given this linked list: 1->2->3->4->5
 *	For k = 2, you should return: 2->1->4->3->5
 *	For k = 3, you should return: 3->2->1->4->5
 */

ListNode* reverseKGroup(ListNode* head, int k) 
{
    ListNode *newHead=new ListNode(0),*pre(newHead),*next,*cur;
    newHead->next=head;
    stack<ListNode*> bin;
    int count(0);
    while(head||count==k)
    {
        if (count==k)
        {
            cur=bin.top();
            bin.pop();
            next=cur->next;
            pre->next=cur;
            while(!bin.empty())
            {
                cur->next=bin.top();
                cur=bin.top();
                bin.pop();
            }
            cur->next=next;
            pre=cur;
            count=0;
        }
        else
        {
            bin.push(head);
            ++count;
            head=head->next;
        }
    }
    return newHead->next;
}

/*
 *	这个和原地逆序list相似,当k=len(list)时,就是原地逆序
 *	就是先记录住pre,然后对之后的每一个node,都把他接到pre的后面
 *	连续循环k次,就是将k个node逆序,然后更改pre的位置
 */
ListNode *reverseKGroup(ListNode *head, int k) 
{
    if(head==NULL||k==1) return head;
    int num=0;
    ListNode *preheader = new ListNode(-1);
    preheader->next = head;
    ListNode *cur = preheader, *nex, *pre = preheader;
    while(cur = cur->next) 
        num++;
    while(num>=k) {
        cur = pre->next;
        nex = cur->next;
        for(int i=1;i<k;++i) {
            cur->next=nex->next;
            nex->next=pre->next;
            pre->next=nex;
            nex=cur->next;
        }
        pre = cur;
        num-=k;
    }
    return preheader->next;
}