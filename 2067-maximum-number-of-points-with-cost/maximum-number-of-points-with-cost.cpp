class Solution {
public:
vector<vector<long long>> dp;
long long f(int i,int j,vector<vector<int>>& points){
    if(i==points.size()-1)return points[i][j];
    long long ans=0;
    if(dp[i][j]!=-1)return dp[i][j];
    for(int k=0;k<points[0].size();k++){
        ans=max(ans,(f(i+1,k,points)-abs(k-j)));
    }
    return dp[i][j]=points[i][j]+ans;
}
    long long maxPoints(vector<vector<int>>& points) {
    //     long long  ans=0;
    //     vector<vector<long long>> dp(points.size()+1,vector<long long>(points[0].size()+1,-0));
    //     // for(int i=0;i<points[0].size();i++){
    //     //     if(dp[0][i]==-1)
    //     //     ans=max(ans,f(0,i,points));
    //     // }

    // for(int i=1;i<=points.size();i++){
    //     for(int j=1;j<points[0].size();j++){

    //     }
    // }
    //     return ans;
     const int r=points.size(), c=points[0].size();
        vector<vector<long long>> dp(2, vector<long long>(c, 0));

        // Initialize 0th row
        for (int j=0; j<c; j++)
            dp[0][j]=points[0][j];

        // DP Calculation
        for (int i=1; i < r; i++) {
            vector<long long> left(c, 0), right(c, 0);

             // Compute max from right downto col j=c-1...0
            right[c-1]=dp[(i-1)&1][c-1];
            for (int j=c-2; j >= 0; j--)
                right[j] = max(right[j+1]-1, dp[(i-1)&1][j]);

            // Compute max from left to col j=0...c-1
            left[0]=dp[(i-1)&1][0];
            dp[i&1][0]=max(left[0], right[0])+points[i][0];
            for (int j=1; j < c; j++){
                left[j]=max(left[j-1]-1, dp[(i-1)&1][j]);
                dp[i&1][j] = max(left[j], right[j])+points[i][j];// update DP
            }
        }

        // Find the maximum value
        return *max_element(dp[(r-1)&1].begin(), dp[(r-1)&1].end());
    }
};