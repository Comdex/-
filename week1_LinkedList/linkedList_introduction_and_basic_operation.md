## Outline
1. Introduce Dummy Node in Linked List
2. Basic skills in Linked List you should know
3. Two pointers
4. Frequent Questions

链表：
> 单向链表(singly linked list)  
双向链表(double linked list)

> 注意：  
链表操作时利用dummy node是一个非常好用的 trick: 只要涉及操作head节点，不妨创建dummy node:
```c++
ListNode *dummy = new ListNode(0);
dummy->next = head;
```

查找 
```java
current = head
// for each item in the list
while(current!=null) {
	// if the data matched the target
	if (target.equals(current.getData())) {
		return true
	}
	// advance current
	current = current.getNext()
}
return false
```

增加节点  
注意在头节点位置和非头节点位置添加节点的区别。

删除
```c++
void delNode(ListNode *prev) 
{
	ListNode *curr = prev->next;
	prev->next = curr->next; //删除curr节点只会使prev节点的next受到影响
	delete curr; // 清理trash指针
}
```
注： 操作Linked List时务必注意边界条件：curr == head, curr == tail 或者 curr = NULL

小问题：如何在常熟时间内删除指定节点，而并不知道该节点的前一个节点。  
>可以把指定节点的后一个节点的值拷贝到指定节点，然后删除这个后一个节点。

删除整个链表：  
delete_linkedlist.c
```c 
void deleteList(struct node** head_ref) {
	struct node* current = *head_ref;
	struct node* next;
	while(current!=NULL) {
		next = current->next;
		free(current);
		current = next;
	}
	*head_ref = NULL;
}
```

### Dummy Node  
Scenario: When the head is not determinated  
1. Remove Duplicates for Sorted List I  
Given a sorted linked list, delete all duplicates such that each element appear only once.
For example, given 1->1->2, return 1->2. Given 1->1->2->2->3, return 1->2->3.
```c
void removeDuplicates(struct node* head) {
	struct node* current = head;
	struct node* next_next;
	if (current == NULL) {
		return;
	}
	/* Traverse the list till last node */
	while(current->next != NULL) {
		if (current->data == current->next->data) {
			next_next = current->next->next;
			free(current->next);
			current->next = next_next;
		} else {
			current = current->next;
		}
	}
}
```


 Remove Duplicates for Sorted List II  
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only 
distinct nubmers from the original list.
For exampe, given 1->2->3->3->4->4->5, return 1->2->5.
given 1->1->1->2->3, return 2->3.
```java
public ListNode deleteDuplicates(ListNode head) {
	if (head == null || head.next == null) {
		return head;
	}
	ListNode dummy = new ListNode(0);
	dummy.next = head;
	head = dummy;
	
	while(head.next != null && head.next.next != null) {
		if (head.next.val == head.next.next.val) {
			int val = head.next.val;
			while(head.next != null && head.next.val == val) {
				head.next = head.next.next;
			}
		} else {
			head = head.next;
		}
	}
	return dummy.next;
}

```

2. Merge Two Sorted Lists  
3. Partition List  
4. Reverse Linked List I,II  


