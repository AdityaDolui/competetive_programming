class Solution {
public:
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
bool check(vector<vector<int>>& heights,int mid){
 queue<pair<int,int>> pq;
 int n=heights.size();
 int m=heights[0].size();

 pq.push({0,0});
vector<vector<int>> vis(n,vector<int>(m,0));
vis[0][0]=1;
 while(!pq.empty()){
    auto it=pq.front();
    pq.pop();
    int i=it.first;
    int j=it.second;
    if(i==n-1 && j==m-1)return true;
    for(int k=0;k<4;k++){
        int x=i+dx[k];
        int y=j+dy[k];

        if(x>=0 && x<n && y>=0&&y<m && !vis[x][y] &&(abs(heights[i][j]-heights[x][y])<=mid)){
            pq.push({x,y});
            vis[x][y]=1;
        }
    }
 }
 return false;
}
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int l=0,h=1e6;

        int ans=0;
        while(l<=h){
            int mid=(l+h)>>1;
            if(check(heights,mid)){
                ans=mid;
                h=mid-1;
            }else l=mid+1;
        }

return ans;


    }
};