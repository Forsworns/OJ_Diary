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
    private int ans = 0;
    private int dfs(TreeNode root){
        if(root==null){
            return 0;
        }
        int l = dfs(root.left);
        int r = dfs(root.right);
        int v = Math.abs(l-r);
        ans += v;
        return root.val+l+r; // the sum of the whole subtree
    }

    public int findTilt(TreeNode root) {
        dfs(root);
        return ans;
    }
}