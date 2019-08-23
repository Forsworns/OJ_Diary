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
    void deleteNode(ListNode* node) {
        // 题干写错了，playground里给的也是两个参数的接口……
        // 但是这个方法有点意思，把下一个节点的信息直接拷贝覆盖到当前节点，而不是下面注释中常用的改变next
        // *node = *(node->next);
        //（考虑一下垃圾回收？
        auto tempNode = node->next;
        *node = *(tempNode);
        delete tempNode;
        tempNode = nullptr;
        // 常规遍历链表
        /*
        auto node = head; 
        if(head->val == n){ // 由于用next判断，head需要提前做特殊情况的处理
            head = head->next;
            return;
        }
        while(true){ 
            if(node->next->val==n){
                node->next = node->next->next;
                return;
            }else{ 
                node = node->next;
            }
        }
        */
    }
};