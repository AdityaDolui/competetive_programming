class Solution {
public:
    int findMaximumLength(vector<int>& nums) {
        int n=nums.size();
        
        vector<pair<int,long long>> dp(n,{0,1e16});
        vector<long long> pre(n);
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+nums[i];
        }

    int mid;
        dp[0]={1,nums[0]};
        for(int i=1;i<n;i++){

              if (nums[i] >= dp[i - 1].second) {
                dp[i].first = max(dp[i - 1].first + 1, dp[i].first); 
                if (dp[i - 1].first + 1 == dp[i].first) {
                    dp[i].second = min(dp[i].second, (long long)nums[i]);
                }
            } else {
                dp[i].first = max(dp[i].first, dp[i - 1].first); 
                if (dp[i].first == dp[i - 1].first) {
                    dp[i].second = min(dp[i].second, dp[i - 1].second + (long long)nums[i]);    
                }
            }


            int idx=-1,ind=-1,l=i,h=n-1;

            while(l<=h){
                mid=(l+h)/2;
                if(pre[mid]>=pre[i-1]+dp[i-1].second){
                    ind=mid;
                    idx=mid;
                    h=mid-1;
                }else l=mid+1;
            }
/*
            if(ind!=-1){
                if(dp[i].first<dp[i-1].first+1){
                    dp[i]={dp[i-1].first+1,pre[ind]-pre[i-1]};
                }
                if(dp[i].first<dp[i-1].first+1){
                     dp[i]={dp[i].first,std::min(pre[ind]-pre[i-1],dp[i].second)};
                }
            }

            if(dp[i].first<dp[i-1].first){
                    dp[i]={dp[i-1].first,dp[i-1].second+pre[i]-pre[i-1]};
                }
                if(dp[i].first<dp[i-1].first){
                     dp[i]={dp[i].first,min(pre[i]-pre[i-1]+dp[i-1].second,dp[i].second)};
                }
        }
       */
       if(idx!=-1){
        dp[idx].first = max(dp[idx].first, dp[i - 1].first + 1);
                if (dp[idx].first == dp[i - 1].first + 1) {
                    dp[idx].second = min(dp[idx].second, pre[idx] - pre[i - 1]);
                }
       }
        }
        return dp[n-1].first;




            
    }
};