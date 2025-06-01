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
    public boolean check(TreeNode root, int targetSum){
         
        targetSum-=root.val;

        if(root.left==null && root.right==null){
            return targetSum==0? true: false;
        }
     //   if(targetSum<0)return false;

        boolean left=(root.left==null)?false: check(root.left,targetSum ) ;
        boolean right=(root.right==null)?false:check(root.right,targetSum);

        return left||right;
    }
    public boolean hasPathSum(TreeNode root, int targetSum) {
          if(root==null){
            return false;
        }
        return check(root,targetSum);
    }
}