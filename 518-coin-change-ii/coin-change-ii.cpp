class Solution {
public:
    long long f(int i,int target,vector<int>& coins,vector<vector<int>> &dp){
        if(target==0)return 1;
        if(target<0)return 0;
        if(i<0)return 0;
        
        if(dp[i][target]!=-1)return dp[i][target];
        long long take=0,nontake=0;
        if(target-coins[i]>=0)
        take=f(i,target-coins[i],coins,dp);
        nontake=f(i-1,target,coins,dp);
        return dp[i][target]=take+nontake;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return f(coins.size()-1,amount,coins,dp);
        
    }
};