class Solution {
public:
int mod=1e9 + 7;
    int f(int n, int k, int target,vector<vector<int>> &dp){
    if(target==0){
        if(n==0)return 1;
        return 0;
    }
        if(n<=0)return 0;
        int ans=0;
        if(dp[n][target]!=-1)return dp[n][target]%mod;
        for(int i=1;i<=k;i++){
            if(i>target)break;
            ans=(ans+f(n-1,k,target-i,dp)%mod)%mod;
        }
        return dp[n][target]= ans%mod;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return f(n,k,target,dp);
    }
};