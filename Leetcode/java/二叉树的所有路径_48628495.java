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
    public void binaryTreePaths(TreeNode root, List<String> paths, List<String> path) {
        path.add(String.valueOf(root.val));
        if(root.left == null && root.right == null){
            paths.add(String.join("->",path));
        } else {
            if(root.left!=null){
                binaryTreePaths(root.left,paths,path);
                path.remove(path.size()-1);
            }
            if(root.right!=null){
                binaryTreePaths(root.right,paths,path);
                path.remove(path.size()-1);
            }
        }
    }

    public List<String> binaryTreePaths(TreeNode root) {
        List<String> paths = new ArrayList<>();
        if(root==null){
            return paths;
        }
        List<String> path = new ArrayList<>();
        binaryTreePaths(root,paths,path);
        return paths;
    }
}