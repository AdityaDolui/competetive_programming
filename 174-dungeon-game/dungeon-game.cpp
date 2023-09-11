class Solution {
public:
    int f(int i,int j,int sum,int mini,vector<vector<int>>& arr,vector<vector<int>> &dp){
        if(i>=arr.size() || j>=arr[0].size())return 1e9;        
         if(dp[i][j]!=-1)return dp[i][j];
          int right=f(i,j+1,sum,mini,arr,dp);
        int down=f(i+1,j,sum,mini,arr,dp);

        int health=min(right,down);
        if(health==1e9)health=0;
        if(health-arr[i][j]>0)health=health-arr[i][j];
        else health=0;
        
        return dp[i][j]=health;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n=dungeon.size();
        int m=dungeon[0].size();

        
        vector<vector<int>> dp1(n+1,vector<int>(m+1,-1));
        return 1+abs(f(0,0,0,0,dungeon,dp1));
    }
};