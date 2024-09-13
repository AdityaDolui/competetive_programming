class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
       
            vector<int> ans(queries.size());
            vector<int> dp(arr.size());
            dp[0]=arr[0];
            for(int i=1;i<arr.size();i++){
                dp[i]=dp[i-1]^arr[i];
            }

            for(int i=0;i<queries.size();i++){

                int s=queries[i][0],e=queries[i][1];
                if(s==0)ans[i]=dp[e];
                else{
                    ans[i]=dp[e]^dp[s-1];
                }
            }
        
        return ans;
    }
};