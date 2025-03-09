class Solution {
    public int jump(int[] nums) {
        int n=nums.length;
        int [] dp =new int[n];

        for(int i=n-2;i>=0;i--){
            int mini=100000;
            for(int k=1;k<=nums[i];k++){
                if((i+k)>=n-1){
                    mini=0;
                    break;
                }
                else{
                    mini=Math.min(mini,dp[i+k]);
                }
            }
            dp[i]=1+mini;
        }
        if(dp[0]>10000)return -1;
        return dp[0];
    }
}