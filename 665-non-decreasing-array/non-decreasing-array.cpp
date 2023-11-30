class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n=nums.size();
        int prev=0;
        bool flag=true;
        vector<bool> check(n,0);
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]){
                if(!flag)return false;
                flag=0;
                if(nums[i]>=prev){
                    nums[i-1]=prev;
                }else {
                    nums[i]=nums[i-1];
                    prev=nums[i];
                }
                
                
            }else prev=nums[i-1];
        }
        return true;
    }
};