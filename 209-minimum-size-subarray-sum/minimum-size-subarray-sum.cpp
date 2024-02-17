class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        vector<int> prev(nums.size()+1,0);
     //   prev[0]=nums[0];
        for(int i=0;i<n;i++)prev[i+1]=prev[i]+nums[i];

        if(prev[n]<target)return 0;

       // for(auto it:prev)cout<<it<<" ";
        
        int ans=INT_MAX;
        int num;
        for(int i=0;i<n;i++){
            int findd=prev[i]+target;
            num=lower_bound(prev.begin(),prev.end(),findd)-prev.begin();
        //    cout<<num<<"-"<<i<<"   ";
            if(num!=prev.size())
           { ans=min(ans,(num-i));}
            
        }

    return ans;

    }
};