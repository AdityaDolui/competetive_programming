class Solution {
public:
int k=1e9+7;
int f(int i,int j,int n,int m,int maxMove, vector<vector<vector<int>>>& dp){
    if(i<0 || j<0 || i>=n || j>=m)return 1;
    if(maxMove==0)return 0;
    if(dp[i][j][maxMove]!=-1)return dp[i][j][maxMove];
    return  dp[i][j][maxMove]=((f(i+1,j,n,m,maxMove-1,dp)%k+f(i-1,j,n,m,maxMove-1,dp)%k)%k+(f(i,j+1,n,m,maxMove-1,dp)%k+f(i,j-1,n,m,maxMove-1,dp)%k)%k)%k;
}
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(maxMove+1,-1)));     
        return f(startRow,startColumn,m,n,maxMove,dp);   
          

    }
};