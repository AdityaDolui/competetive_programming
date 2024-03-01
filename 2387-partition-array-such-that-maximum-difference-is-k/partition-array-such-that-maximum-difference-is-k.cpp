class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=1;
        int n=nums.size();
        if(nums[n-1]-nums[0]<=k)return ans;

        int i=0;
        int mini,maxi;
        mini=nums[0];
     //   maxi=nums[0];
        while(i<n){
            if(nums[i]-mini>k){
                ans++;
                mini=nums[i];
            }
            i++;
        }
        return ans;
    }
};