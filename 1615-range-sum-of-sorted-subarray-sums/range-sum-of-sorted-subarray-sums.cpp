class Solution {
public:
int mod=1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int ans=0;
        int k=0;
        long long num=n*(n+1)/2;
        vector<long long> arr(num);
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum=(sum+nums[j])%mod;
                arr[k++]=sum;
            }
        }
        sort(arr.begin(),arr.end());
      //  for(auto it:arr)cout<<it<<" ";
        for(int i=left-1;i<right;i++){
            ans=(ans%mod+(arr[i]))%mod;
        }
        return ans;
    }
};