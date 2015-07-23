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