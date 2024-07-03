class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size()<=4)return 0;
        sort(nums.begin(),nums.end());
        int k=3;
        int n=nums.size();
        int i=0,j=n-1;
        int minVal=INT_MAX;

        minVal = min(minVal, nums[n-4] - nums[0]);
        minVal = min(minVal, nums[n-1] - nums[3]);
        minVal = min(minVal, nums[n-2] - nums[2]);
        minVal = min(minVal, nums[n-3] - nums[1]);
        return minVal;
    }
};