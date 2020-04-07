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
    // 分情况，防止出现跳过中间节点的情况m，那样就不是路径了
    private int helper(TreeNode root, int sum, boolean pass){
        if(root==null){
            return 0;
        }
        int ans = 0;
        if(sum==root.val){
            ans++;
        }
        if(pass){
            ans += helper(root.left,sum-root.val, true);
            ans += helper(root.right,sum-root.val, true);
        }else{
            ans += helper(root.left,sum,false);
            ans += helper(root.left,sum-root.val,true);
            ans += helper(root.right,sum,false);
            ans += helper(root.right,sum-root.val,true);
        }
        return ans;
    }
    public int pathSum(TreeNode root, int sum) {
        return helper(root,sum,false); 
    }
}