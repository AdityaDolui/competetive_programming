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
    int check(TreeNode node,int[] maxi){
        if(node==null)return 0;

        int left=Math.max(0,check(node.left,maxi));
        int right=Math.max(0,check(node.right,maxi));

        maxi[0]=Math.max(maxi[0],(left+right+node.val));
        // maxi[0]=Math.max(maxi[0],node.val);
        
        return Math.max(right,left)+node.val;
    }
    public int maxPathSum(TreeNode root) {
        int[] maxi={Integer.MIN_VALUE};
        check(root,maxi);
        return maxi[0];
    }
}