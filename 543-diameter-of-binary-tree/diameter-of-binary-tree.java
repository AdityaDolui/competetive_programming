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
    int maxi=0;
    public int check(TreeNode node){
        if(node==null)return 0;

        int lf=check(node.left);
        int rt=check(node.right);
        maxi=Math.max(maxi,lf+rt);
        return Math.max(lf,rt)+1;
    }
    public int diameterOfBinaryTree(TreeNode root) {
        check(root);
        return maxi;
    }
}