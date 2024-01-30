class Solution {
public:
    int dx[8]={1,1,-1,-1,2,2,-2,-2};
    int dy[8]={2,-2,2,-2,1,-1,1,-1};
    int maxi=0;
    double f(int i,int j,int move,int n,int c,vector<vector<vector<double>>> &dp){
        if(i<0 || i>=n||j<0 || j>=n)return 0;
        if(move==0)return 1;
        if(dp[i][j][move]!=-1)return dp[i][j][move];
        c++;
        maxi=max(c,maxi);
        double cnt=0;
        for(int k=0;k<8;k++)cnt+=f(i+dx[k],j+dy[k],move-1,n,c,dp);
        return dp[i][j][move]=cnt;
    }
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(n,vector<vector<double>>(n,vector<double>(k+1,-1)));
        double dig=f(row,column,k,n,0,dp);
        cout<<dig<<" "<<maxi;
        double ans=dig/pow(8,maxi);;
        return ans;
    }
};