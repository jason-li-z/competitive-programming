/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode
 * next; ListNode() {} ListNode(int val) { this.val = val; } ListNode(int val,
 * ListNode next) { this.val = val; this.next = next; } }
 */
class Solution {

    public ListNode reverseListRecursive(ListNode head) {
        if (head == null || head.next == null)
            return head;
        ListNode rev = reverseListRecursive(head.next);
        head.next.next = head; // Head's next node will point to head ("reverse")
        head.next = null; // Change head's next to null as we have the rev pointing towards us
        return rev;

    }

    public ListNode reverseListIterative(ListNode head) {
        if (head == null || head.next == null)
            return head;

        ListNode curr = head; // Points to current
        ListNode prev = null;

        while (curr != null) {
            ListNode nextNode = curr.next;
            curr.next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;

    }
}