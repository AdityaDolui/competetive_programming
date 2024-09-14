class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
   
    
    bool f(int i,int j,vector<vector<int>> &grid,vector<vector<bool>>& vis, int health, vector< vector<vector<int>>>& dp){
          if(i<0 || i>=grid.size()|| j<0 || j>=grid[0].size()||vis[i][j]||health<=0)return false;
        
           if(grid[i][j]==1){
            if(health<=1)return false;
            health=health-1;
        }
        
        if(i==grid.size()-1 && j==grid[0].size()-1){
            return true;
        }
        
        
      
        
        if(dp[i][j][health]!=-1)return dp[i][j][health];
       
        
     
        
        vis[i][j]=true;
        
        
        
        for(int k=0;k<=3;k++){
            int x=dx[k]+i;
            int y=dy[k]+j;
           
           
           bool ans=f(x,y,grid,vis,health,dp);
            if(ans)return dp[i][j][health]= true;
             
            
        }
        vis[i][j]=0;
        return dp[i][j][health]= false;
        
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m=grid[0].size();
        int n=grid.size();
        vector<vector<bool>> vis (n,vector<bool>(m,0));
       // vector<vector<int>> dp(n,vector<int>(m,-1));
        vector<vector<vector<int>>> dp (n, vector<vector<int>>(m,vector<int>(health+1,-1)));
        bool ans= f(0,0,grid,vis,health,dp);
       
        return ans;
    }
};