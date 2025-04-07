class Solution {
    static boolean flag=false;
    public boolean check(int i, int tar ,int[] nums,int[][] dp){
         if(tar==0 ){
            flag=true;
            return true;
            }
        if(i>=nums.length || tar<0){
            return false;
        }
        if(dp[i][tar]!=-1)return dp[i][tar]==1?true:false;
        boolean ans=(check(i+1,tar-nums[i],nums,dp) || check(i+1,tar,nums,dp) );
        dp[i][tar]=ans==true?1:0;

        return ans;
       
    }
    public boolean canPartition(int[] nums) {
      
     
      int sum=Arrays.stream(nums).sum();
       int[][] dp=new int[nums.length][(sum/2)+1];
       for(int i=0;i<nums.length;i++){
        Arrays.fill(dp[i],-1);
       }
      if((sum&1)==1)return false;
    return check(0,sum/2,nums,dp);
    
    }
}