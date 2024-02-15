class Solution {
public:
bool flag=true;
int f(int i,int target,vector<int>& nums,vector<vector<int>> &dp){
    
    if(target==0){
        flag=false;
        cout<<"yes ";
        return 0;
    }
    if(i<0)return -1e9;
    if(dp[i][target]!=-1)return dp[i][target];
    int take=-1e9,nontake=0;
    
    if(target>=nums[i])take=1+f(i-1,target-nums[i],nums,dp);
    nontake=f(i-1,target,nums,dp);
    

    return dp[i][target]=max(take,nontake);
}
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {

        int n=nums.size()-1;
        vector<vector<int>> dp(n+1,vector<int>(target+2,-1));
        int ans= f(n,target,nums,dp);
        if(flag)return -1;
        return ans;
    }
};