/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
// 递归方法，还是用了O(n)的空间复杂度
class Solution {
    private ListNode front = null;

    private boolean recursive(ListNode nd){
        if(nd!=null){
            if(!recursive(nd.next)){
                return false;
            }
            if(nd.val!=front.val){
                return false;
            }
            front = front.next;
        }
        return true;
    }

    public boolean isPalindrome(ListNode head) {
        front = head;
        return recursive(head);
    }
}