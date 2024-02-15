class Solution {
public:
    int f(int k,vector<vector<int>> & piles,vector<vector<int>> &dp,int ind=0){
            if(ind>=piles.size()||k<=0)return 0;
            if(dp[ind][k]!=-1)return dp[ind][k];
           int total=0;
           int ans=f(k,piles,dp,ind+1);
            int sz=piles[ind].size();
           for(int i=0;i< min(sz,k);i++){
               total+=piles[ind][i];
               ans=max(ans,total+f(k-(i+1),piles,dp,ind+1));

           }
            return  dp[ind][k]=ans;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        

       
       vector<vector<int>> dp(piles.size(),vector<int>(k+1,-1));
        return f(k,piles,dp);

    }
};