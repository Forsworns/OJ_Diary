/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
// 从右子树开始做中序遍历，记录累加和；平时都是先左子树，读出来是增序列
class Solution {
    int sum=0;
    public TreeNode convertBST(TreeNode root) {
        if(root==null){
            return null;
        }
        if(root.left==null&&root.right==null){
            sum+=root.val;
            root.val=sum;
            return root;
        }
        if(root.right!=null){
            convertBST(root.right);
        }
        sum+=root.val;
        root.val=sum;
        if(root.left!=null){
            convertBST(root.left);
        }
        return root;
    }
}