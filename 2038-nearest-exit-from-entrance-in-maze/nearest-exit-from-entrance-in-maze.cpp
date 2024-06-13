class Solution {
public:
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {

        int n=maze.size();
        int m=maze[0].size();
         
       
        vector<vector<int>> vis(n,vector<int>(m,0));

        int  ans=-1;
       queue<pair<int,pair<int,int>>> q;
        q.push({0,{entrance[0],entrance[1]}});
        vis[entrance[0]][entrance[1]]=1;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int dist=it.first;
            int i=it.second.first;
            int j=it.second.second;
            if(!(i==entrance[0] && j==entrance[1]))
            if(i==0 || j==0 || i==n-1 ||j==m-1)return dist;
           // if(vis[i][j])continue;
            for(int k=0;k<4;k++){
                int x=i+dx[k];
                int y=j+dy[k];

                if(x>=0 && y>=0 && x<n && y<m && maze[x][y]=='.'&& !vis[x][y]){
                    vis[x][y]=1;
                    q.push({dist+1,{x,y}});
                }
            }
        }
        return ans;
    }
};