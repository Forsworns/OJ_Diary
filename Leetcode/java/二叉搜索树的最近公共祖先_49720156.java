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
    private int min, max;
    private Map<Integer,Pair> interval; 

    private class Pair {
        int min;
        int max;
        Pair(int x,int y){
            min = x;
            max = y;
        }
    }

    private void computeInterval(TreeNode root){
        if(root.left!=null && root.right!=null) {
            computeInterval(root.left);
            computeInterval(root.right);
            interval.put(root.val, new Pair(interval.get(root.left.val).min,interval.get(root.right.val).max));
        }
        else if(root.right!=null){
            computeInterval(root.right);
            interval.put(root.val, new Pair(root.val,interval.get(root.right.val).max));
        } else if(root.left!=null){
            computeInterval(root.left);
            interval.put(root.val, new Pair(interval.get(root.left.val).min,root.val));
        } else{
            interval.put(root.val, new Pair(root.val,root.val));
        }
        // String str = String.format("root: %d Min: %d Max: %d",root.val, interval.get(root.val).min,interval.get(root.val).max);
        // System.out.println(str);
    }

    private TreeNode searcher(TreeNode root){
        if(root.val==min||root.val==max){
            return root;
        }
        // 不需要检查子树是否为null，因为到了叶子节点只可能是上面那种情况
        if(min>interval.get(root.left.val).max){ // 如果比左子树的最大值大，舍弃左子树
            return searcher(root.right);
        }else if(max<interval.get(root.right.val).min){ // 如果比右子树的最小值小，舍弃右子树
            return searcher(root.left);
        }else{
            return root;
        }
    }

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        min = Math.min(p.val,q.val);
        max = Math.max(p.val,q.val);
        interval = new HashMap<>();
        computeInterval(root);
        return searcher(root);
    }
}