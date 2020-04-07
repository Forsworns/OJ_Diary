/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //双指针拼接起来
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ans = nullptr;
        if(headA == NULL || headB == NULL) {
            return ans;
        } 
        ListNode *nodeA = headA, *nodeB = headB;
        bool flagA = false, flagB = false;
        while(nodeA!=nodeB){
            if(nodeA->next==nullptr) {
                if(!flagA || !flagB){
                    nodeA = headB;
                    flagA = true;
                }else{ // the second time when reach the end 
                    break;
                }
            } else {
                nodeA = nodeA->next;
            }
            if(nodeB->next==nullptr) {
                if(!flagA || !flagB){
                    nodeB = headA;     
                    flagB = true;
                }else{
                    break;               
                }
            } else {
                nodeB = nodeB->next;  
            }
        }
        if(nodeA==nodeB){
            ans = nodeA;
        }
        return ans;
    }
};