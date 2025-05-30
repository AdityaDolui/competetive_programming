/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int ans=0;
    void f(int depth,TreeNode node){
        if(node.right==null && node.left==null){
            ans=Math.max(depth,ans);
            return ;
        }
        if(node.right!=null) f(depth+1,node.right);
          if(node.left!=null) f(depth+1,node.left);
    }
    public int maxDepth(TreeNode root) {
        if(root==null)return 0;
        f(1,root);
        return ans;
    }
}