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

	public static void main(String[] args) {
		ListNode n1 = new ListNode(1);
		ListNode n2 = new ListNode(3);
		ListNode n3 = new ListNode(6);
		ListNode n4 = new ListNode(8);
		ListNode n5 = new ListNode(9);
		n1.next = n2;
		n2.next = n3;
		n3.next = n4;
		n4.next = n5;

		ListNode n6 = new ListNode(2);
		ListNode n7 = new ListNode(7);
		n6.next = n7;

		Solution solution = new Solution();
		ListNode list = solution.mergeTwoLists(n1, n6);
		ListNode temp  = list;
		while( temp!= null) {
			System.out.print(temp.val+"\t");
			temp = temp.next;
		}
		System.out.println();
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