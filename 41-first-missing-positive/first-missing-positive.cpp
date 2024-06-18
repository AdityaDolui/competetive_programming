class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        bool one =false;
        for(auto &it:nums){
            if(it==1)one=true;
            if(it<=0)it=1;
            
        }
        if(!one)return 1;

    for(int i=0;i<n;i++){
        if(nums[i]<=n){
            int val=abs(nums[i])-1;
        nums[val]=-abs(nums[val]);
        }
    }
    //for(auto it:nums)cout<<it<<" ";
    for(int i=0;i<n;i++){
        if(nums[i]>0)return i+1;
    }
    return n+1;

        // while(i<n){
        //     if(nums[i]>0 && nums[i]<=n && nums[i]!=nums[nums[i]-1]){
        //         swap(nums[i],nums[nums[i]-1]);
        //     }else i++;
        // }
        // for(int i=0;i<n;i++){
        //     if(i+1!=nums[i])return i+1;
        // }
        // return n+1;
    }
};