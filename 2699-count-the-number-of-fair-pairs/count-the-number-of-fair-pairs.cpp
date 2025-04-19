class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans=0;

        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            int it=nums[i];
           
            int a=lower_bound(nums.begin()+i+1,nums.end(),lower-it)-nums.begin();
            int b=upper_bound(nums.begin()+1+i,nums.end(),upper-it)-nums.begin();
           
            ans+=(b-a);
            cout<<ans<<" ";
        }
        return ans;
    }
};