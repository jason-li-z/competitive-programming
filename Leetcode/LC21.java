/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode
 * next; ListNode() {} ListNode(int val) { this.val = val; } ListNode(int val,
 * ListNode next) { this.val = val; this.next = next; } }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {

        ListNode ans = new ListNode(0);
        ListNode d = ans;

        while (l1 != null && l2 != null) {
            if (l1.val < l2.val) {
                ans.next = l1;
                ans = ans.next;
                l1 = l1.next;
            } else {
                ans.next = l2;
                ans = ans.next;
                l2 = l2.next;
            }
        }

        // Case 1: L1 still has remains as L2 reached end
        while (l1 != null) {
            ans.next = l1;
            ans = ans.next;
            l1 = l1.next;
        }

        // Case 2: L2 still has remains as L1 reached end
        while (l2 != null) {
            ans.next = l2;
            ans = ans.next;
            l2 = l2.next;
        }

        return d.next;
    }
}