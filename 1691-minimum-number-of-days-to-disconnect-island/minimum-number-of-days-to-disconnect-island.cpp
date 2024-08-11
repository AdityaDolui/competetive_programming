class Solution {
public:
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
     void f(int i,int j,vector<vector<int>>& grid,vector<vector<int>> &vis ){
         vis[i][j]=1;

        for(int k=0;k<4;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            if(x>=0 && x<grid.size() && y>=0 && y<grid[0].size() && !vis[x][y] && grid[x][y]){
                f(x,y,grid,vis);
            }
        }

     }
     int check(vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis (n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]&&!vis[i][j]){
                    f(i,j,grid,vis);
                    cnt++;
                    if(cnt>1)return 2;
                }
            }
        }
        return 1;
     }
    int minDays(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis (n,vector<int>(m,0));
    int cnt=0;
    int cal=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    cal++;
                if(!vis[i][j]){
                    f(i,j,grid,vis);
                    cnt++;
                    if(cnt>1)return 0;
                }
            }
            }
        }
        if(cal==1 || cal==0)return cal;
    int ans=0;
          for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    grid[i][j]=0;
                ans=max(ans,check(grid));
                grid[i][j]=1;
                }
            }
          }
        if(ans==1)return 2;
        return 1;
    }
};