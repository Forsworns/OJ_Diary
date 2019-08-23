/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while(head!=nullptr && head->val==val){
            head = head->next;
        }
        auto node = head;
        while(node!=nullptr){
            if(node->next!=nullptr && node->next->val==val){
                node->next = node->next->next;
            }else{
                node = node->next; 
            }
        }
        return head;
    }
};