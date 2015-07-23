## Outline
1. Introduce Dummy Node in Linked List
2. Basic skills in Linked List you should know
3. Two pointers
4. Frequent Questions

### 链表：
> 单向链表(singly linked list)  
> 双向链表(double linked list)

> **注意：**  
> 链表操作时利用dummy node是一个非常好用的 trick: 只要涉及操作head节点，不妨创建dummy node:
```c++
ListNode *dummy = new ListNode(0);
dummy->next = head;
```

#### 查找 
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

#### 增加节点  
> 注意在头节点位置和非头节点位置添加节点的区别。

#### 删除
```c++
void delNode(ListNode *prev) 
{
	ListNode *curr = prev->next;
	prev->next = curr->next; //删除curr节点只会使prev节点的next受到影响
	delete curr; // 清理trash指针
}
```
**注：** 操作Linked List时务必注意边界条件：curr == head, curr == tail 或者 curr = NULL

> 小问题：如何在常熟时间内删除指定节点，而并不知道该节点的前一个节点。  
> 可以把指定节点的后一个节点的值拷贝到指定节点，然后删除这个后一个节点。

删除整个链表：  `delete_linkedlist.c`
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
*Scenario: When the head is not determinated*  
#### 1.1 Remove Duplicates for Sorted List I  
> Given a sorted linked list, delete all duplicates such that each element appear only once.
> For example, 
> Given 1->1->2, return 1->2.  
> Given 1->1->2->2->3, return 1->2->3.  
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
#### 1.2  Remove Duplicates for Sorted List II  
> Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
> For example, 
> Given 1->2->3->3->4->4->5, return 1->2->5.
> Given 1->1->1->2->3, return 2->3.
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
#### 2. Merge Two Sorted Lists  
> Merge two sorted linked list and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.  
```java
public class Solution {
	public ListNode mergeTwoLists(ListNode l1,ListNode l2) {
		if (l1 == null)
			return l2;
		if (l2 == null)
			return l1;
		ListNode head = l1.val < l2.val ? l1:l2;
		ListNode dummy = new ListNode(0);
		while (l1 != null && l2 != null) {
			if (l1.val < l2.val) {
				dummy.next = l1;
				dummy = l1;
				l1 = l1.next;
			} else {
				dummy.next = l2;
				dummy = l2;
				l2 = l2.next;
			}
		}

		if (l1 == null) {
			dummy.next = l2;
		}
		if (l2 == null) {
			dummy.next = l1;
		}
		return head;
	}
}

class ListNode {
	int val;
	ListNode next;
	ListNode(int x) {
		val = x;
		next = null;
	}
}
``` 
#### 3. Partition List  
> **Reorder List**
> Given a linked list and a value x, write a function to reorder this list such that all nodes less than x come before the nodes greater than or equal to x.
```c
ListNode *reorder_list(ListNode *head, int x) {
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
```
#### 4. Reverse Linked List I,II  
```c
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
```

### Basic Skills
1. Insert a Node in Sorted List
2. Remove a Node from Linked List
3. Reverse a Linked List
4. Merge Two Linked Lists
5. Find the Middle of a Linked LIst

##### Sort List
 > Sort a linked list in O(n log n) time using constant space complexity.
 > Hint: merge sort.  
 
 *O(n log n )的 sort 算法：* Merge sort, Heap sort  
```
mergeSort(arr[], l, r):
if r>l
	1. Find the middle point to divide the array into two halves:
		middle m = (l+r)/2
	2. Call mergeSort for first half:
		Call mergeSort(arr, l, m)
	3. Call mergeSort for second half:
		Call mergeSort(arr, m+1, r)
	4. Merge the two halves sorted in step 2 and step 3:
		Call merge(arr, l, m, r)
```
Sort List Code:
```java
public class Solution {	
	private ListNode findMiddle(ListNode head) {
		ListNode slow = head, fast = head.next;
		while(fast != null && fast.next != null) {
			fast = fast.next.next; // fast每次比slow快一步，当fast结束时，slow刚好在middle
			slow = slow.next;
		}
		return slow;
	}

	public ListNode sortList(ListNode head) {
		if (head == null || head.next == null) {
			return head;
		}

		ListNode mid = findMiddle(head);
		ListNode right = sortList(mid.next);
		mid.next = null; // 先右边后左边，并截断左边，接着排序左边的一半
		ListNode left = sortList(head);

		return merge(left, right);
	}

	public ListNode merge(ListNode head1, ListNode head2) {
		ListNode dummy = new ListNode(0);
		ListNode tail = dummy;
		while (head1 != null && head2 != null) {
			if (head1.val < head2.val) {
				tail.next = head1;
				head1 = head1.next;
			} else {
				tail.next = head2;
				head2 = head2.next;
			}
			tail = tail.next;
		}
		if (head1 != null) {
			tail.next = head1;
		} else {
			tail.next = head2;
		}
		return dummy.next;
	}
}
```