ListNode* reorder_list(ListNode *head, int x) {
	ListNode *new_head = NULL;
	ListNode *a_dummy = new ListNode(0); 
	ListNode *a_curr = a_dummy;
	ListNode *b_dummy = new ListNode(0);
	ListNode *b_curr = b_dummy;

	while(head) {
		ListNode *next = head->next;
		head->next = NULL;
		if (head->val < x) {
			a_curr->next = head;
			a_curr = head;
		} else {
			b_curr->next = head;
			b_curr = head;
		}
		head = next;
	}

	a_curr->next = b_dummy->next;
	new_head = a_dummy->next;

	delete a_dummy;
	delete b_dummy;

	return new_head;
}