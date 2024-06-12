class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> ans(nums.size(),1);
        int i=0,j=nums.size()-1,k=0;
       while(k<=j){
        cout<<k<<" ";
        if(nums[k]==2){
            swap(nums[k],nums[j]);
            j--;
            continue;
        }
        if(nums[k]==0)swap(nums[i++],nums[k]);
        
        k++;
       }
       

    }
};