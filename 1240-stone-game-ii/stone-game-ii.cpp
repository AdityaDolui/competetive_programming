class Solution {
public:
    int f(int i, int M,bool chance,vector<int>& piles, vector<vector<vector<int>>>& dp ){
        if(i>=piles.size())return 0;
        if(dp[i][M][chance]!=-1)return dp[i][M][chance];
    if(chance){
        int sum=0;
        int ans=0;
        for(int k=1;k<=2*M && k+i<=piles.size();k++){
            sum+=piles[i+k-1];
            ans=max(ans,sum+f(i+k,max(k,M),0,piles,dp));
        }
        return dp[i][M][chance]=ans;
    }else{
     
        int ans=INT_MAX;
        for(int k=1;k<=2*M && k+i<=piles.size();k++){
            ans=min(ans,f(i+k,max(k,M),1,piles,dp));
        }
        return  dp[i][M][chance]= ans;
    }
    }
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(2,-1)));
        return f(0,1,1,piles,dp);
    }
};