class Solution {
public:

    int maximumLength(vector<int>& nums, int k) {
        unordered_map<int,int> last_seen;
        int n=nums.size();
        vector<vector<int>> dp(nums.size(),vector<int>(k+1,0));
        vector<int> longest_sub(k+1,0);
        dp[0][0]=1;
        last_seen[nums[0]]=0;
        longest_sub[0]=1;
        for(int i=1;i<n;i++){
            dp[i][0]=1;
            int maxi=min(i,k);
            if(last_seen.find(nums[i])!=last_seen.end()){
                for(int j=0;j<=maxi;j++){
                    dp[i][j]=max(dp[i][j],dp[last_seen[nums[i]]][j]+1);
                }
            }
            last_seen[nums[i]]=i;
            for(int j=0;j<=maxi;j++){
                if(j==k)break;
                dp[i][j+1]=max(dp[i][j+1],longest_sub[j]+1);
            }
            for(int j=0;j<=maxi;j++){
                longest_sub[j]=max(longest_sub[j],dp[i][j]);
            }
        }
        int ans=0;
         for(int j=0;j<=k;j++){
                ans=max(longest_sub[j],ans);
            }
            return ans;
    }
};