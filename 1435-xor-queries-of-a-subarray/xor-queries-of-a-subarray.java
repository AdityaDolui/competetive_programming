class Solution {
    public int[] xorQueries(int[] arr, int[][] queries) {
        int[] ans=new int[queries.length];
        int [] dp=new int[arr.length];
    
    int n=arr.length;
    dp[0]=arr[0];
        for(int i=1;i<n;i++){
            dp[i]=dp[i-1]^arr[i];
        }
        for(int i=0;i<queries.length;i++){
             int s=queries[i][0],e=queries[i][1];
                if(s==0)ans[i]=dp[e];
                else{
                    ans[i]=dp[e]^dp[s-1];
                }
        }
        return ans;
    }
}