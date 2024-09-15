class Solution {
public:
    long long f(int i,int j,vector<int>& a, vector<int>& b,vector<vector<long long>>& dp ){
        if(j>=b.size()){
            if(i>=a.size())return 0;
            
            return INT_MIN;
        }
       if(i>=a.size())return 0;
        if(dp[i][j]!=LLONG_MIN)return dp[i][j];
        long long int take=0,nonTake=0;
        take=(long long)a[i]*b[j]+f(i+1,j+1,a,b,dp);
        nonTake=f(i,j+1,a,b,dp);
        
        return dp[i][j]=max(take,nonTake);
    }
    long long maxScore(vector<int>& a, vector<int>& b) {
        vector<vector<long long>> dp(4,vector<long long>(b.size(),LLONG_MIN));
        return f(0,0,a,b,dp);
        
    }
};