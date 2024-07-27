class Solution {
public:
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

    int minimumTime(vector<vector<int>>& grid) {
        
        if(grid[0][1]>1 && 1<grid[1][0])return -1;
        priority_queue<pair<int,pair<int,int>> ,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

        int n=grid.size();
        int m=grid[0].size();
        pq.push({0,{0,0}});
        vector<vector<int>> vis(n,vector<int>(m,0));
        vis[0][0]=true;
            vector<vector<int>> dist (n,vector<int>(m,INT_MAX));
            dist[0][0]=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            
            int i=it.second.first;
            int j=it.second.second;
            int val=it.first;
            vis[i][j]=true;
            if(i==n-1 && j==m-1)return val;
            
            for(int k=0;k<4;k++){
                int x=i+dx[k];
                int y=j+dy[k];
                
                if(x>=0 && x<n && y>=0 && y<m){
                     
                    if(val+1>=grid[x][y]){
                        int next=val+1;
                        if(next<dist[x][y])
                       {
                        dist[x][y]=val;
                         pq.push({next,{x,y}});
                         }                      
                        
                    }
                    else{
                        int diff=grid[x][y]-val;
                        if(diff&1==1)diff--;

                         int next=val+1+diff;
                        if(next<dist[x][y])
                       {
                        dist[x][y]=val;
                         pq.push({next,{x,y}});
                         }
                    }
                }

            }

        }
        cout<<"helllo";
        if(dist[n-1][m-1]==INT_MAX)
        return -1;
        return dist[n-1][m-1];
    }
};