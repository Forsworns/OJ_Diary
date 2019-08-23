/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 快慢指针的思路
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==nullptr){
            return false;
        }
        auto ps = head; // slow pointer
        auto pf = head->next; // fast pointer
        while(pf!=nullptr){
            pf=pf->next;
            if(pf!=nullptr){
                pf = pf->next;
            }else{
                return false;
            }
            ps = ps->next;
            if(ps==pf){
                return true;
            }
        }
        return false;
    }
};