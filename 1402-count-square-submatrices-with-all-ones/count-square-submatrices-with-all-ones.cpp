class Solution {
public:
    int f(int i,int j, vector<vector<int>>& matrix,  vector<vector<int>> & dp){
        if(i>= matrix.size() || j>=matrix[0].size())return 0;

        if(dp[i][j]!=-1)return dp[i][j];
        int rt=f(i,j+1,matrix,dp);
        int dw=f(i+1,j,matrix,dp);
        int dg=f(i+1,j+1,matrix,dp);

        if(matrix[i][j]){
            return dp[i][j]=1+min(dg,min(dw,rt));
        }
        return dp[i][j]=0;

        

    }
    int countSquares(vector<vector<int>>& matrix) {
        int ans=0;
        vector<vector<int>> dp  (matrix.size(),vector<int>(matrix[0].size(),-1));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){

                ans+=f(i,j,matrix,dp);
            }
        }
        return ans;
    }
};