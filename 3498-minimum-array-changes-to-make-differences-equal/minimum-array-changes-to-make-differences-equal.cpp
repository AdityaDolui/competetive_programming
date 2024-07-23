class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
      
       vector<int> freq(k+1),v;
        int n=nums.size();
         int ans=n/2;
       for(int i=0;i<n/2;i++){
        int diff= abs(nums[i]-nums[n-i-1]);

        freq[diff]++;
        int a=nums[i],b=nums[n-i-1];
        v.push_back(max(max(a,b),k-min(a,b)));
       }
    sort(v.begin(),v.end());
    n=n/2;
    for(int i=0;i<freq.size();i++){
        int rest=n-freq[i];
        int second=lower_bound(v.begin(),v.end(),i)-v.begin();
        ans=min(ans,rest+second);
    }
    return ans;
    }
};