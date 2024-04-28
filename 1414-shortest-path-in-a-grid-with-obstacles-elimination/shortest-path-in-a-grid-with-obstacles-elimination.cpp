class Solution {
public:
    int f(int i,int j,int k,vector<vector<bool>> &vis, vector<vector<int>>& grid,vector<vector<vector<int>>>& dp){
          int n = grid.size();
        int m = grid[0].size();

        if(i<0 || i>=n ||j<0 || j>=m||vis[i][j]){
          //  cout<<"out"<<" ";
            return 1e9;}

            if(dp[i][j][k]!=-1)return dp[i][j][k];

        
         if(i==0 && j==0){
            return dp[i][j][k]=0;
        }

        if(grid[i][j]==1){
            if(k<=0)return dp[i][j][k]= 1e9;
            else k--;
        }

       //cout<<i<<"-"<<j<<"  ";

        
        vis[i][j]=1;
      
        int u=1+f(i-1,j,k,vis,grid,dp);
        int l=1+f(i,j-1,k,vis,grid,dp);
        int r=1+f(i,j+1,k,vis,grid,dp);
        
        int d=1+f(i+1,j,k,vis,grid,dp);

         vis[i][j]=0;

        return dp[i][j][k]= min(l,min(r,min(u,d)));
        
    }
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(k+1,-1)));
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        int ans= f(n-1,m-1,k,vis,grid,dp);
        if(ans>=1e9)return -1;
        else return ans;
    }
};