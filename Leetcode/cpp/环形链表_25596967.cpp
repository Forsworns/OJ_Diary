/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 哈希表，存下访问过的节点
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> addrs;
        auto p = head;
        while(p!=nullptr){
            if(addrs.find(p)==addrs.end()){
                addrs.insert(p);
            }else{
                return true;
            }
            p = p->next;
        }
        return false;
    }
};