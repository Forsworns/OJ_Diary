/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
// wdnmd，读题！是二叉搜索树，还排序干嘛……用中序遍历出的就是有序数组
class Solution {
    TreeNode prev = null;
    int res = Integer.MAX_VALUE;

    private void dfs(TreeNode root){
        if(root==null){
            return;
        }
        dfs(root.left);
        if(prev!=null) res = Math.min(res, root.val-prev.val);
        prev = root;
        dfs(root.right);
    }

    public int getMinimumDifference(TreeNode root) {
        dfs(root);
        return res;
    }
}