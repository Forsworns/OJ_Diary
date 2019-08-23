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
        while(head!=nullptr && head->val==val){ // 先把特殊情况处理掉
            head = head->next; // 如果head值就是val，则没法直接通过改next做
        }
        auto node = head;
        while(node!=nullptr){ // 当前node不是val，查看next是不是val
            if(node->next!=nullptr && node->next->val==val){
                node->next = node->next->next; // next是val的话跳过它
                // 此时当前节点node不变
            }else{
                node = node->next; // next不是val，当前node移动 
            }
        }
        return head;
    }
};