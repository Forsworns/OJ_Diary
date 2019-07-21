/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 根据题意，这是一个前序遍历；补充上对应的()就可以了，注意左儿子为空时，可以省略
class Solution {
private:
    string ans = "";
    string num2str(int num){
        stringstream ss;
        ss<<num;
        return ss.str();
    }
    void preOrder(TreeNode* t){
        ans += num2str(t->val);
        
        if(t->left==NULL&&t->right!=NULL){ // 叶节点也不用区分
            ans+="()";
        }else if(t->left!=NULL){
            ans+="(";
            preOrder(t->left);
            ans+=")";
        }
        if(t->right!=NULL){
            ans+="(";
            preOrder(t->right);
            ans+=")";
        }
        
    }
public:
    string tree2str(TreeNode* t) {
        if(t==NULL){
            return "";
        }
        preOrder(t);
        return ans;
    }
};