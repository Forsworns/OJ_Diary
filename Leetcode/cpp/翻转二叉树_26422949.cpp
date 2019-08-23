class Solution {
private:
    TreeNode* traverse(TreeNode* oldNode){
        if(oldNode==nullptr){
            return nullptr;
        }
        TreeNode* newNode = new TreeNode(oldNode->val);
        newNode->right = traverse(oldNode->left);
        newNode->left = traverse(oldNode->right);
        return newNode;
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* newRoot; // 不能在invertTree内创建否则该指针是局部变量无法返回,但是如果是返回的new 出来的可以
        newRoot = traverse(root);
        return newRoot;
    }
};