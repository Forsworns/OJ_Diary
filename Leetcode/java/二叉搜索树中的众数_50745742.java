/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
 // 利用二叉搜索树中序遍历是有序数组的性质，转换成有序数组的众数问题
 
class Solution {
    List<Integer> l = new ArrayList<>();
    int maxN = 0;
    int nowN = 1>>>32-1;
    int now = 0;

    private void midOrder(TreeNode root){
        if(root.left!=null){
            midOrder(root.left);
        }
        if(root.val==now){
            nowN++;
        }else{
            if(nowN>maxN){
                l.clear();
                l.add(now);
                maxN = nowN;
            }else if(nowN==maxN){
                l.add(now);
            }
            now = root.val;
            nowN=1;
        }
        if(root.right!=null){
            midOrder(root.right);
        }
    }

    public int[] findMode(TreeNode root) {
        if(root==null){
            return new int[0];
        }
        midOrder(root);
        if(nowN>maxN){ // 需要再检查一遍
            l.clear();
            l.add(now);
            maxN = nowN;
        }else if(nowN==maxN){
            l.add(now);
        }   

        int[] ans = new int[l.size()];
        for(int i=0;i<l.size();++i){
            ans[i] = l.get(i);
        }
        return ans;
    }
}