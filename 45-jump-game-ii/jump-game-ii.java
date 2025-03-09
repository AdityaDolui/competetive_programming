class Solution {
    public int jump(int[] arr) {
          if(arr[0]==0)return 0;
          int n=arr.length;
       int[] dp =new int[n];
       for(int i=n-2;i>=0;i--){
           if(arr[i]==0)dp[i]= 10000+1;
           int mini=10000000;
           for(int k=1;k<=arr[i];k++){
            if((k+i)>=n-1)mini=Math.min(mini,0);
            else
            mini=Math.min(mini,dp[i+k]);
        }
         dp[i]=1+mini;
        
           
       }
      
       if( dp[0]>=1e4)return -1;
       return  dp[0];
    }
}