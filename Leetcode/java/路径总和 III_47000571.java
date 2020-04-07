/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
// 记录经过的路径上是否有把当前节点作为终点的等于sum的路径
class Solution {
    private int helper(TreeNode root, int sum, int[] path, int pos){
        if(root==null){
            return 0;
        }
        int ans=0;
        int pathSum = root.val;
        if(pathSum==sum){
            ans++;
        }
        for(int i=pos-1;i>=0;--i){
            pathSum+=path[i];
            if(pathSum==sum){
                ans++;
            }
        }
        path[pos]=root.val;
        ans+=helper(root.left,sum,path,pos+1);
        ans+=helper(root.right,sum,path,pos+1);
        return ans;
    }
    public int pathSum(TreeNode root, int sum) {
        int[] path = new int[1000];
        return helper(root,sum,path,0); 
    }
}