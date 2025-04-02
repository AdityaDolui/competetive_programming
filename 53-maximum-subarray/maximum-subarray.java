class Solution {
    public int maxSubArray(int[] nums) {
        int sum=0;
        int maxi=Integer.MIN_VALUE;
        for(int val:nums){
            sum+=val;
            maxi=Math.max(maxi,sum);

            if(sum<0)sum=0;
        }
        return maxi;
    }
}