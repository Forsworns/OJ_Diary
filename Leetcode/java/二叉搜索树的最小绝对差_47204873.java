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
    private void dfs(TreeNode root, List l){
        if(root==null){
            return;
        }
        l.add(root.val);
        dfs(root.left,l);
        dfs(root.right,l);
    }
    public int getMinimumDifference(TreeNode root) {
        List<Integer> vals = new ArrayList<>();
        dfs(root,vals);
        Collections.sort(vals);
        int ans = vals.get(1)-vals.get(0);
        for(int i=2;i<vals.size();++i){
            ans = Math.min(ans,vals.get(i)-vals.get(i-1));
        }
        return ans;
    }
}