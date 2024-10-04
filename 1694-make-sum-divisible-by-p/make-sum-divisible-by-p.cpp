class Solution {
public:

    int minSubarray(vector<int>& nums, int p) {
        long long tot=0;
        tot=accumulate(nums.begin(),nums.end(),0,[p](int sum ,int val){
            return (val+sum)%p;
        
        });
        if(tot%p==0)return 0;
        long long tar=tot%p;
        int ans=nums.size();
        long long sum=0;
        
        unordered_map<int,int> map;
        map[0]=-1;
        for(int i=0;i<nums.size();i++){
            int it=nums[i];
            sum=(sum+it)%p;
            
            if(map.find((sum-tar+p)%p)!=map.end()){
                ans=min(ans,(i-map[(sum-tar+p)%p]));
            }
            map[sum]=i;
        }
        
        return nums.size()==ans?-1:ans;
    }
};