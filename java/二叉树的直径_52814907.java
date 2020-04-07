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
    class NdInfo{
        int h;
        int d;
        NdInfo(int diameter,int height){
            d = diameter;
            h = height;
        }
    }

    NdInfo dfs(TreeNode nd){
        if(nd==null){
            return new NdInfo(0,0);
        }
        NdInfo l = dfs(nd.left), r = dfs(nd.right);
        int d = Math.max(l.h+r.h,Math.max(l.d,r.d));
        int h = Math.max(l.h,r.h)+1;
        return new NdInfo(d,h);
    }

    public int diameterOfBinaryTree(TreeNode root) {
        NdInfo ans = dfs(root);
        return ans.d;
    }
}