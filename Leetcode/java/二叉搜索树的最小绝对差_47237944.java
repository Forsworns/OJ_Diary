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
    private void dfs(TreeNode root, List l){
        if(root==null){
            return;
        }
        dfs(root.left,l);
        l.add(root.val);
        dfs(root.right,l);
    }
    public int getMinimumDifference(TreeNode root) {
        List<Integer> vals = new ArrayList<>();
        dfs(root,vals);
        int ans = vals.get(1)-vals.get(0);
        for(int i=2;i<vals.size();++i){
            ans = Math.min(ans,vals.get(i)-vals.get(i-1));
        }
        return ans;
    }
}