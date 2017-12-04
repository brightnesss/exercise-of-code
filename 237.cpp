/*
 *	237. Delete Node in a Linked List
 *	Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.
 *	Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, 
 *	the linked list should become 1 -> 2 -> 4 after calling your function.
 */

/*
 *	用node->next的值来代替node的值,最后将尾结点改为NULL
 */

void deleteNode(ListNode* node) 
{
    while(node->next->next)	//直到尾结点的前一个结点
    {
        node->val=node->next->val;
        node=node->next;
    }
    node->val=node->next->val;
    node->next=NULL;
}