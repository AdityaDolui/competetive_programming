class Solution {
    int f(int i,int[] nums, int target,int[][] dp){
        if(i>=nums.length){
            return target==1000?1:0;
        }
      //  if(dp[i][target]!=1)return dp[i][target];
         dp[i][target]= f(i+1,nums,target+nums[i],dp)+ f(i+1,nums,target-nums[i],dp);
         return dp[i][target];
    }
    public int findTargetSumWays(int[] nums, int target) {
        
        // int[][] dp =new int[nums.length+1][30001];
        // for(int[] arr:dp){
        //     Arrays.fill(arr,-1);
        // }
          int[][] dp = new int[nums.length + 1][3001];
        for (int[] row : dp) {
            Arrays.fill(row, -1); // Initialize all cells with -1 to indicate uncomputed states.
        }
        return f(0,nums,target+1000,dp);


    }
}