class Solution {
public:
int f(int i,int n,int s,vector<int> & prices, vector<vector<int>> & dp){
    if(i==n)return 0;
    if(dp[i][s]!=-1)return dp[i][s];
    int take=INT_MAX,nontake=INT_MAX;
    take=prices[i]+f(i+1,n,i+1,prices,dp);
    if(s>0)nontake=f(i+1,n,s-1,prices,dp);

    return dp[i][s]=min(take,nontake);
}
    int minimumCoins(vector<int>& prices) {
        int n=prices.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    return f(0,n,0,prices,dp);
    }
};