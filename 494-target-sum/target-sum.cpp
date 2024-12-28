class Solution {
public:

int f(int i,vector<int>& nums, int target,vector<vector<int>> &dp){
    
    if(i==nums.size())return target==1000;
    if(dp[i][target]!=-1)return dp[i][target];
    return  dp[i][target]= f(i+1,nums,target-nums[i],dp)+f(i+1,nums,target+nums[i],dp);
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(nums.size()+1,vector<int>(3001,-1));
        return f(0,nums,target+1000,dp);
    }
};