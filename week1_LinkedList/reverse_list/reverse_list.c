#include <stdio.h>
#include <stdlib.h>

typedef struct _ListNode {
	int value;
	struct _ListNode* next;
} ListNode;

ListNode* reverse_list(ListNode *head) {
	ListNode* prev = head;
	ListNode* curr = head->next;
	ListNode* next = NULL;
	while(curr->next != NULL) {
		next = curr->next;
		prev->next = NULL;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	curr->next = prev;
	head->next = NULL;

	return next;
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

	ListNode* ret = reverse_list(&a);

	print_list(ret);

	return 0;
}

