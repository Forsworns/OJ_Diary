/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
    private int ans = 0;
    private int depth = 0;

    private void dfs(Node root){
        if(root==null){
            ans = Math.max(depth,ans);
            return;
        }
        depth++;
        if(root.children.size()==0){
            ans = Math.max(depth,ans);
        }
        for(Node c:root.children){
            dfs(c);
        }
        depth--;
        return;
    }

    public int maxDepth(Node root) {
        dfs(root);
        return ans;
    }
}