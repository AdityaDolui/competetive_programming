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
 public class   BinarySearchTree{
    TreeNode node;

    public BinarySearchTree(){
        node=null;
    }

    public void insert(int val){
        node=insertRec(node,val);
    }

    public TreeNode insertRec(TreeNode node, int val){

        if(node==null){
            node=new TreeNode(val);
            return node;
        }

        if(val<node.val){
            node.left=insertRec(node.left,val);
        }else{
            node.right=insertRec(node.right,val);
        }
        return node;
    }


 }
class Solution {
    public TreeNode sortedArrayToBST(int[] nums, int left , int right){
        if(left>right)return null;

        int mid=(left+right)/2;
        TreeNode node=new TreeNode(nums[mid]);

        node.right=sortedArrayToBST(nums,mid+1,right);
          node.left=sortedArrayToBST(nums,left,mid-1);
          return node;
    }
    public TreeNode sortedArrayToBST(int[] nums) {
        // BinarySearchTree tree=new BinarySearchTree();

        // for(int val:nums){
        //     tree.insert(val);
        // }
        // return tree.node;
        return sortedArrayToBST(nums,0,nums.length-1);
    }
}