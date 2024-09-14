class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maxi){
                int k=i;
                while(k<nums.size() && nums[k]==maxi){
                    k++;
                }
                ans=max(ans,(k-i));
                i=k-1;
            }
        }
        return ans;
    }
};