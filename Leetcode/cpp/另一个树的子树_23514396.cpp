class Solution {
// 之前递归的时候想错了，在比较两棵树是否相同时，多回溯了判断过或即将判断的情况
private:
    bool equal(TreeNode* s, TreeNode* t){
        if(s!=NULL && t!=NULL && s->val == t->val){
            return equal(s->left,t->left) && equal(s->right,t->right);
        }else{
            return t==NULL && s==NULL;
        }
    }
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s!=NULL){
            return equal(s,t) || isSubtree(s->left,t)||isSubtree(s->right,t); // 注意该情况下判断是否是同一棵树，并且需要考虑左右子树
        }else{
            return equal(s,t);   
        }
    }
};