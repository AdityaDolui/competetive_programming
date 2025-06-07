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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        
        List<List<Integer>> ans=new ArrayList<>();

        if(root==null)return ans;
        Queue<TreeNode> dq=new LinkedList<>();
        int check=1;

        dq.add(root);

        while(!dq.isEmpty()){
        
            int size=dq.size();
            int[] arr=new int[size];

            for(int i=0;i<size;i++){
                int j=check==1?i:size-1-i;
                TreeNode node=dq.poll();
                arr[j]=node.val;
                if(node.left!=null)dq.add(node.left);
                 if(node.right!=null)dq.add(node.right);
            }
            ans.add(Arrays.stream(arr).boxed().toList());
            check=check^1;
        }
        return ans;

    }
}