/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode* merge(TreeNode* t1,TreeNode* t2){
        TreeNode* res;
        if(t1==nullptr && t2==nullptr){
            res = nullptr;
        }else if(t1!=nullptr && t2==nullptr){
            res = new TreeNode(t1->val);
            res->left = merge(t1->left,t2);
            res->right = merge(t1->right,t2);
        }else if(t1==nullptr && t2!=nullptr){
            res = new TreeNode(t2->val);
            res->left = merge(t1,t2->left);
            res->right = merge(t1,t2->right);
        }else{
            res = new TreeNode(t1->val+t2->val);
            res->left = merge(t1->left,t2->left);
            res->right = merge(t1->right,t2->right);
        }
        return res;
    }
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode* merged;
        merged = merge(t1,t2);
        return merged;
    }
};