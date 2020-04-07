/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
// 翻转链表后半部分，O(1)的空间复杂度

class Solution {
    private ListNode traverse(ListNode head){
        ListNode slow = head, fast = head;
        while(fast.next!=null && fast.next.next!=null){
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }

    private ListNode reverse(ListNode head){
        ListNode prev=null,curr = head;
        while(curr!=null){
            ListNode next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    public boolean isPalindrome(ListNode head) {
        if(head==null){
            return true;
        }
        boolean ans=true;
        ListNode secondHead, firstEnd;
        firstEnd = traverse(head);
        secondHead = reverse(firstEnd.next);

        ListNode first = head, second = secondHead; 
        while(second!=null){
            if(first.val!=second.val){
                ans = false;
                break;
            }
            first = first.next;
            second = second.next;
        }
        reverse(secondHead);
        // firstEnd.next = reverse(secondHead);; // 不需要再赋值一次，因为原来的链表并没有断开，我们翻转第二部分是输入的firstEnd.next
        return ans;
    }
}