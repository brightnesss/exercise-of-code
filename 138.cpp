/*
 *	138. Copy List with Random Pointer
 *	A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
 *	Return a deep copy of the list.
 */

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

//这种方法会使用一个hash表来存放,空间复杂度O(n)
RandomListNode *copyRandomList(RandomListNode *head)
{
	unordered_map<RandomListNode*, RandomListNode*> map;
	map[NULL] = NULL;
	RandomListNode *p(head);
	while (p != NULL)
	{
		map[p] = new RandomListNode(p->label);
		p = p->next;
	}
	RandomListNode *newhead(map[head]);
	p = newhead;
	while (head != NULL)
	{
		p->next = map[head->next];
		p->random = map[head->random];
		p = p->next;
		head = head->next;
	}
	return newhead;
}

/*
 *	题目中已经告知随机指针只会指向链表中的节点或者是空节点
 		第一次遍历:每次在建立新节点时,将新节点插入到旧链表中相应的节点后面,如旧链表1->2->3->4，在遍历和插入之后就会变成1->1'->2->2'->3->3'->4->4'
 		第二次遍历:将新节点里的random指向旧节点random指向的节点的next
 		第三次遍历:恢复旧链表的形态,并将新链表分割开
 *	这个算法的时间复杂度是O(3N) = O(N),额外空间复杂度是O(1)
 */
void copyNext(RandomListNode *head)	//第一次遍历
{
    while(head!=NULL)
    {
        RandomListNode *next=new RandomListNode(head->label);	//创建新的
        next->random=head->random;	//但random还是旧的
        next->next=head->next;	//放next插入head之后
        head->next=next;
        head=head->next->next;
    }
}

void copyRandom(RandomListNode *head)	//第二次遍历
{
    while(head!=NULL)
    {
        if (head->random!=NULL) head->next->random=head->random->next;	//新结点(head->next)的random指向旧结点(head)random的next
        head=head->next->next;
    }
}

RandomListNode* spilt(RandomListNode *head)		//第三次遍历
{
    RandomListNode *newhead=head->next,*tmp;
    while(head!=NULL)
    {
        tmp=head->next;
        head->next=tmp->next;
        head=head->next;
        if (tmp->next) tmp->next=tmp->next->next;
    }
    return newhead;
}

RandomListNode *copyRandomList(RandomListNode *head) 
{
    if (!head) return head;
    copyNext(head);
    copyRandom(head);
    return spilt(head);
}