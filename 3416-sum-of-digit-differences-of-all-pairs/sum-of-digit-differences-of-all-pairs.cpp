class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        vector<vector<int>> dp(10,vector<int>(10,0));

        for(auto it:nums){
            for(int j=0;it>0;it=it/10,j++){
                dp[j][it%10]++;
            }
        }
        long long ans=0;
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                ans+=dp[i][j]*(nums.size()-dp[i][j]);
            }
        }
        return ans/2;
    }
};