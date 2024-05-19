class Solution {
public:
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

    vector<vector<int>> safeDiist(vector<vector<int>> &grid){
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> ans(n,vector<int>(m,-1));
        queue<pair<int,int>> pq;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1)
                {ans[i][j]=0;
                pq.push({i,j});}
            }
        }
        while(!pq.empty()){
            auto it=pq.front();
            pq.pop();
            int i=it.first;
            int j=it.second;
            
            for(int k=0;k<4;k++){
                int x=i+dx[k];
                int y=j+dy[k];
                if(x>=0 && x<n && y>=0 && y<m && ans[x][y]==-1){
                    ans[x][y]=ans[i][j]+1;
                    pq.push({x,y});

                }
            }
        }

    return ans;
    }

    bool check (vector<vector<int> > &ans,int mid){
         int n=ans.size();
      
        queue<pair<int,int>> pq;
        pq.push({0,0});
        if(ans[0][0]<mid || ans[n-1][n-1]<mid)return false;
        vector<vector<bool>> vis(n,vector<bool>(n,0));
        vis[0][0]=1;
        while(!pq.empty()){
             auto it=pq.front();
            pq.pop();
            int i=it.first;
            int j=it.second;
            if(i==ans.size()-1 && j==ans[0].size()-1 && ans[i][j]>=mid)return true;
            for(int k=0;k<4;k++){
                int x=i+dx[k];
                int y=j+dy[k];
                if(x>=0 && x<n && y>=0 && y<n && vis[x][y]==0 &&ans[x][y]>=mid){
                    
                    pq.push({x,y});
                    vis[x][y]=1;

                }
            }
        }
        return false;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
     vector<vector<int>> safeDist(n,vector<int>(m));
     safeDist=safeDiist(grid);
    //  for(auto it:safeDist){
    //     for(auto iit:it){
    //         cout<<iit<<" ";
    //     }
    //     cout<<endl;
    //  }

    int l=0,h=(n-1)*2;
    int res=0;
    while(l<=h){
        int mid=(l+h)>>1;

        if(check(safeDist,mid)){
            res=mid;
            l=mid+1;
        }else h=mid-1;
    }


     return res;
    }
};