class Solution {
public:
    int f(int i1,int j1,int j2,vector<vector<int>> & grid, vector<vector<vector<int>>>& dp){
        int n=grid.size();
        int i2=j1+i1-j2;
        if(i1>=grid.size() || j1>=grid.size()|| j2>=grid.size() ||i2>=n)return INT_MIN;

         if(grid[i1][j1]==-1 || grid[i2][j2]==-1)return INT_MIN; 
        
        if(i1==n-1 && j1==n-1)return grid[i1][j1];
        if(dp[i1][j1][j2]!=-1)return dp[i1][j1][j2];
        int ans=grid[i1][j1];
       if(j1!=j2){
        ans+=grid[i2][j2];
       }
       int num=max(f(i1+1,j1,j2,grid,dp),max(f(i1,j1+1,j2,grid,dp),max(f(i1+1,j1,j2+1,grid,dp),f(i1,j1+1,j2+1,grid,dp))));
            
            return dp[i1][j1][j2]=ans+num;
        
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        if(n==1){
            if(grid[0][0])return 1;
        return 0;}
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(n,-1)));
        int ans=f(0,0,0,grid,dp);
        if(ans<0)return 0;
        return ans;
    }
};