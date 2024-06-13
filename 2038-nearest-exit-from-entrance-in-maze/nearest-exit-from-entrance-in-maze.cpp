class Solution {
public:
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

    int f(int i,int j,vector<vector<char>>& maze ,vector<int>& entrance,int dir, vector<vector<vector<int>>>& dp){
        if(i>=maze.size() || i<0||j<0 ||j>=maze[0].size())return 1e9;

        if(maze[i][j]=='+')return 1e9;
        if(!(i==entrance[0] && j==entrance[1])){
       //     cout<<"here";
        if(i==0 || j==0||i==maze.size()-1 || j==maze[0].size()-1){
        //    cout<<"****Now***";
            return 0;}
        }
        if(dir!=-1 && dp[i][j][dir]!=-1)return dp[i][j][dir];

        int ans=1e9;
       // cout<<i<<"-"<<j<<"  ";
        maze[i][j]='+';
        for(int k=0;k<4;k++){
            int x=i+dx[k];
            int y=j+dy[k];

            ans=min(ans,f(x,y,maze,entrance,k,dp)+1)   ; 
        }
         maze[i][j]='.';
         if(dir!=-1)
        return dp[i][j][dir]=ans;
        return ans;
        

    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n=maze.size();
        int m=maze[0].size();
         
        vector<vector<vector<int>>> dp (n,vector<vector<int>>(m,vector<int>(5,-1)));
       int ans= f(entrance[0],entrance[1],maze,entrance,-1,dp);
       
        if(ans>=1e9)return  -1;
        return ans;
    }
};