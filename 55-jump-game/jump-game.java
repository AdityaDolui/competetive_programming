class Solution {
    public boolean canJump(int[] nums) {
       int maxi=0;
       for(int i=0;i<nums.length;i++){

            if(maxi>=nums.length-1)return true;
             if(i>maxi)return false;
            maxi=Math.max(maxi,i+nums[i]);
           
       }
       return true;
    }
}