class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int i=0,j=0;
        int cnt=0;
        int cntAns=0;
        int ans =0;
        int n=nums.size();
        vector<int> arr(n+1);
        unordered_map<int,int> map;
        // map[0]=-1;
        // for(int i=0;i<n;i++){
        //     if(nums[i-1]&1)map[cnt++]=i;
        // }
     
        cnt=0;
        while(j<n){
            if(nums[j]&1){
                k--;
            cntAns=0;}
        //   if(cnt==k){
        //         //ans++;
        //         cntAns=0;
        //     }
            while(k==0){
                if(nums[i]&1)k++;
                i++;
                cntAns++;
                 
            }
            ans+=cntAns;
               j++;
        }
         return ans;
    }
};