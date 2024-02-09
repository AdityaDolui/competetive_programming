class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int fst=-1,lst=-1;
        bool flag=true;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                if(flag){
                    fst=i;
                    lst=i;
                    flag=false;
                }
                lst=i;
            }
        }
        return {fst,lst};
    }
};