class Solution {
public:
    int f(int i,vector<int> &nums,int k,int prev,vector<vector<vector<int>>> &dp){
        if(i==nums.size())return 0;

       if(dp[i][k][prev+1]!=-1)return dp[i][k][prev+1];

        if(prev==-1 ||nums[i]==nums[prev] ){
           return dp[i][k][prev+1]= max(f(i+1,nums,k,i,dp)+1,f(i+1,nums,k,prev,dp));
        }else{           
            int a=0;
            if(k>0)a=f(i+1,nums,k-1,i,dp)+1;
            int b =f(i+1,nums,k,prev,dp);
            return dp[i][k][prev+1]= max(a,b);
        }
    }
    int maximumLength(vector<int>& nums, int k) {
        
        int ans=0;
       // int maxi=*max_element(nums.begin(),nums.end());
        vector<vector<vector<int>>> dp(nums.size(),vector<vector<int>>(k+1,vector<int>(nums.size()+2,-1)));
      // vector<vector<int>> dp(nums.size(),vector<int>(k+1,-1));
       return f(0,nums,k,-1,dp);
    }
};