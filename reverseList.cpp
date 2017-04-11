// leetcode No.206 Reverse Linked List

ListNode* reverseList(ListNode* head) 
{
	stack<ListNode*> bin;
	while (head)
	{
		bin.push(head);
		head = head->next;
	}
	if (!bin.empty())
	{
		ListNode* rehead = bin.top();
		ListNode* temp = rehead;
		bin.pop();
		while (!bin.empty())
		{
			temp->next = bin.top();
			bin.pop();
			temp = temp->next;
		}
		temp->next = NULL;
		return rehead;
	}
	else
	{
		ListNode* rehead = NULL;
		return rehead;
	}
}	   


ListNode* reverseList(ListNode* head) 
{
	ListNode* pre = NULL;
	ListNode* next;
	while(head)
	{
		next = head->next;
		head->next = pre;
		pre = head;
		head = next;
	}
	return pre;
}