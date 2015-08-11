#include <stdio.h>
#include <stdlib.h>

typedef struct _ListNode {
	int value;
	struct _ListNode* next;
} ListNode;

ListNode* reverseList(ListNode *head) {
	if (head==NULL)
		return NULL;
	ListNode* prev = head;
	ListNode* curr = head->next;
	while(curr) {
		prev->next = curr->next;
		curr->next = head;
		head = curr;
		curr = prev->next;
	}
	return head;
}



void print_list(ListNode *head) {
	do {
		printf("%d\t\n", head->value);
		head = head->next;
	} while(head);
}

int main(int argc, char const *argv[])
{
	ListNode a;
	a.value = 1;

	ListNode b;
	b.value = 2;

	ListNode c;
	c.value = 3;

	a.next = &b;
	b.next = &c;

	c.next = NULL;

	print_list(&a);

	//ListNode* ret = reverse_list(&a);
	ListNode* ret = reverseList(&a);

	print_list(ret);

	return 0;
}

