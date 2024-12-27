class Solution {
public:

int f(int i,vector<int>& nums, int target){
    
    if(i==nums.size())return !target;

    return f(i+1,nums,target-nums[i])+f(i+1,nums,target+nums[i]);
}
    int findTargetSumWays(vector<int>& nums, int target) {
        return f(0,nums,target);
    }
};