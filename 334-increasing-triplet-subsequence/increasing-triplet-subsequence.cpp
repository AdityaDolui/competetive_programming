class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
     vector<int> arr;
     arr.push_back(nums[0]);

    for(int i=1;i<nums.size();i++){
        if(nums[i]>arr.back()){
            arr.push_back(nums[i]);
            if(arr.size()==3)return true;
        }
        else{
            auto it=lower_bound(arr.begin(),arr.end(),nums[i])-arr.begin();
            arr[it]=nums[i];
        }
    }

    return false;


        

    }
};