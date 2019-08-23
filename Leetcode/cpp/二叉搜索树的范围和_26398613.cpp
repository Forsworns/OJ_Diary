/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 注意L和R都是包含
// 最初分得太复杂了……实际上节点比R小时，不管左儿子多大，左儿子的右儿子都有可能是合法的，不好讨论；节点比L大时同理
// 所以直接这么简单得剪一下枝就行了，不用考虑太复杂
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        int ans = 0;
        searchBST(root,ans,L,R);
        return ans;
    }
    
    void searchBST(TreeNode* root, int &sum, const int& L, const int& R){
        if(root==nullptr){
            return;
        }
        
        if(root->val<L){ // 当前小于等于L，左边可以丢弃，只需要考虑右节点
            searchBST(root->right,sum,L,R);   
        }else if(root->val>R){
            searchBST(root->left,sum,L,R);     
        }else{
            sum += root->val;
            searchBST(root->left,sum,L,R);
            searchBST(root->right,sum,L,R);
        }
    }
};