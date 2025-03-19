class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                int j=i,k=3;
                ans++;
                while(j<n && k){
                    nums[j]=nums[j]^1;
                    j++;
                    k--;
            }
                if(k){
                    //cout<<i<<endl;
                    // for(auto it:nums)cout<<it<<" ";
                    return -1;
                }
            }
            //cout<<i<<"- ";
            //for(auto it:nums)cout<<it<<" ";
            // cout<<"*** ";
            
}
       // for(auto it:nums)cout<<it<<" ";
      
        return ans;
    }
};