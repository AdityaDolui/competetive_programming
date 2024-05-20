class Solution {
public:
 int mini=INT_MAX;
 int dx[4]={1,-1,0,0};
 int dy[4]={0,0,1,-1};
 int q=0;
    int f(int i,int j,vector<vector<int>>& grid,vector<vector<bool>> &vis,int val, vector<vector<vector<int>>> &dp){
        if(i==grid.size()-1 && j==grid.size()-1){
          //  cout<<val<<"**";
            val=max(val,grid[i][j]);
         //   mini=min(mini,val);
            return val;
        }
        if(dp[i][j][val]!=-1)return dp[i][j][val];

        // cout<<i<<"-"<<val<<"-"<<j<<"  ";
        // if(val>mini || grid[i][j]>mini){
        //     q++;
        //     return dp[i][j][val]=val;}
       
        val=max(val,grid[i][j]);
        int l=INT_MAX;
        for(int k=0;k<4;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            if(x>=0 && x<grid.size()&&y>=0 && y<grid[0].size()&&!vis[x][y]){
                 vis[x][y]=1;
            l=min(l,f(x,y,grid,vis,val,dp));
            vis[x][y]=0;
            }
        }
        return dp[i][j][val]=l;;


    }
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size() ;
        int m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,0));
         vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(2510,-1)));
        vis[0][0]=1;
        return f(0,0,grid,vis,0,dp);
        cout<<q;
       // return a;
        return mini;

    }
};