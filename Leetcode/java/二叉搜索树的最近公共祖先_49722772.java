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
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        // 不需要那么麻烦得求每个节点包含的区间，但是思路是类似的，看在不在一棵树上就行了
        int pV = p.val;
        int qV = q.val;
        TreeNode nd = root;
        while(nd!=null){
            if(nd.val>p.val && nd.val>q.val){
                nd = nd.left;
            }else if(nd.val<p.val && nd.val<q.val){
                nd = nd.right;
            }else{
                return nd;
            }
        }
        return null;
    }
}