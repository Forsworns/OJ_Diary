/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
// 读到一个数组里，但是用了O(n)的空间复杂度
class Solution {
    public boolean isPalindrome(ListNode head) {
        ArrayList<Integer> arr = new ArrayList<>();
        while(head!=null){
            arr.add(head.val);
            head = head.next;
        }
        for(int i=0;i<arr.size()/2;++i){
            if(!arr.get(i).equals(arr.get(arr.size()-1-i))){
                return false;
            }
        }
        return true;
    }
}