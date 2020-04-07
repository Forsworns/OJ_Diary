/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    private boolean isLeaf(TreeNode root){
        return root.right==null && root.left==null;
    }

    private int dfs(TreeNode root, boolean isLeft){
        if(root==null){
            return 0;
        }
        if(isLeaf(root)){
            if(isLeft){
                return root.val;
            }else{
                return 0;
            }
        }else{
            return dfs(root.left,true)+dfs(root.right,false);
        }
    }

    public int sumOfLeftLeaves(TreeNode root) {
        return dfs(root,false);
    }
}