class Solution {
public:
    
    int maximumLength(vector<int>& nums,int k) {
       int n=nums.size();
       vector<vector<int>> dp(n,vector<int>(k,0));
        int maxi=0;
       for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            int rem=(nums[i]+nums[j])%k;
            dp[i][rem]=max(dp[i][rem],dp[j][rem]+1);
            maxi=max(maxi,dp[i][rem]);
        }
       }
       return maxi+1;    
    }
};