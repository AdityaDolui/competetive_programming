class Solution {

    public int findValue(int[][] queries , int i, int target, int q,int [][] dp){
        if(target==0)return q;

        if(q>=queries.length || target<0)return 1005;

        if(dp[target][q]!=-1)return dp[target][q];
        int ans=findValue(queries,i,target,q+1,dp);

        if(queries[q][0]<= i && queries[q][1]>=i) ans=Math.min(ans,findValue(queries,i,target-queries[q][2],q+1,dp));
        
        return dp[target][q]= ans;

    }

    public int minZeroArray(int[] nums, int[][] queries) {

        int ans=-1;

       for(int i=0;i<nums.length;i++){
        int [][] dp= new int[nums[i]+1][queries.length];
        Arrays.stream(dp).forEach(row-> Arrays.fill(row,-1));
        ans=Math.max(ans,findValue(queries,i,nums[i],0,dp));
       }
       return (ans>queries.length)? -1:ans;

    }
}