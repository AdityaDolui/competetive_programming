class Solution {
public:
 int f(int i,int j,int k,vector<vector<bool>> &vis, vector<vector<int>>& grid,vector<vector<vector<int>>>& dp){
          int n = grid.size();
        int m = grid[0].size();
        if(i==0 && j==0){
            return dp[i][j][k]=0;
        }

        if(i<0 || i>=n ||j<0 || j>=m||vis[i][j]){
          //  cout<<"out"<<" ";
            return 1e9;}

            if(dp[i][j][k]!=-1)return dp[i][j][k];

        
         

        if(grid[i][j]==1){
            if(k<=0)return dp[i][j][k]= 1e9;
            else k--;
        }

       //cout<<i<<"-"<<j<<"  ";

        
        vis[i][j]=1;
        
       int r=1+f(i,j+1,k,vis,grid,dp);
       
        int u=1+f(i-1,j,k,vis,grid,dp);
         int l=1+f(i,j-1,k,vis,grid,dp);
       
       
        
        int d=1+f(i+1,j,k,vis,grid,dp);

         vis[i][j]=0;

        return dp[i][j][k]= min(l,min(r,min(u,d)));
        
    }
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    int minimumObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        cout<<n<<" "<<m;
       // vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(k+1,-1)));
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        
        // int ans= f(n-1,m-1,k,vis,grid,dp);
        // if(ans>=1e9)return -1;
        // else return ans;

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        
       
        while(!pq.empty()){
            auto it=pq.top();
         //   cout<<"a ";
            pq.pop();
            int i=it.second.first;
             int j=it.second.second;
             int obst=it.first;
             if(i==n-1 && j==m-1)return obst;
            if(vis[i][j])continue;
            vis[i][j]=1;
             
            for(int k=0;k<4;k++){
                int x=i+dx[k];
                int y=j+dy[k];
             //   cout<<x<<" "<<y<<" - ";
                if(x>=0 && x<n && y>=0 && y<m){
                  // cout<<"b ";
                    if(!vis[x][y]){
                    if(grid[x][y]==1)pq.push({obst+1,{x,y}});
                    else pq.push({obst,{x,y}});
                    }
                }

            }
        }

    return -1;
    }
};