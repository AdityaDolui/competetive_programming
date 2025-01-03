class Solution {
    public int waysToSplitArray(int[] nums) {
       long  ans=0;
       long  sum=0;

       for(int val:nums){
        sum+=val;
       } 
       long currSum=0;
       for(int i=0;i<nums.length-1;i++){
            currSum+=nums[i];
            if(currSum>=(sum-currSum)){
                ans++;
            }
       }
       return (int)ans;
    }
}