class Solution {
public:
    int f(int i,int m,int n,int prev,int target,vector<int>& houses, vector<vector<int>>& cost,vector<vector<vector<int>>> & dp){
        if(i==m){
       //     cout<<"Hi"<<target<<" ";
            if(target==0)return 0;
            else {
                //cout<<"here";
            return 1e9;}
        }
        if(target<0){
        //    cout<<"K ";
        return 1e9;}
        if(dp[i][target][prev]!=-1)return dp[i][target][prev];
        if(houses[i]!=0){
          //  cout<<"here ";
            if(prev!=houses[i])return dp[i][target][prev]=f(i+1,m,n,houses[i],target-1,houses,cost,dp);
            else return dp[i][target][prev]= f(i+1,m,n,houses[i],target,houses,cost,dp);
        }
        int sum=INT_MAX;

        for(int k=1;k<=n;k++){
            if(prev!=k)
            {
                sum=min(sum,cost[i][k-1]+f(i+1,m,n,k,target-1,houses,cost,dp));}
            else sum=min(sum,cost[i][k-1]+f(i+1,m,n,k,target,houses,cost,dp));
        }
        return dp[i][target][prev]=sum;

    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> dp (m, vector<vector<int>>(target+1,vector<int>(n+1,-1)));
        int ans=f(0,m,n,0,target,houses,cost,dp);
        if(ans>=1e9)return -1;
        return ans;
    }
};