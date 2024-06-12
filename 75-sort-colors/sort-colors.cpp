class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> ans(nums.size(),1);
        int i=0,j=nums.size()-1;
        for(auto it:nums){
            if(it==0)ans[i++]=0;
            if(it==2)ans[j--]=2;
        }
        nums=ans;

    }
};