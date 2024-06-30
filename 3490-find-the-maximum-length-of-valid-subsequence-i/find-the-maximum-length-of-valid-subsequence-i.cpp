class Solution {
public:
    int f(int i,bool odd,vector<int>& nums,int cnt ){
        if(i==nums.size())return cnt;

        if(odd){
            if((nums[i]&1)==0)return f(i+1,0,nums,cnt+1);
            else return  f(i+1,1,nums,cnt);
        }
        else{
            if((nums[i]&1))return f(i+1,1,nums,cnt+1);
            else return  f(i+1,0,nums,cnt);
        }
    }
    int maximumLength(vector<int>& nums) {
        int n=nums.size();
       vector<int> arr;
        vector<vector<int>> dp(n,vector<int>(2,-1));
        int cnt=0,cnt2=0;
        
        int maxi=max(f(0,0,nums,0),f(0,1,nums,0));
          cout<<maxi;
        for(int i=0;i<n;i++){
            if(nums[i]&1)cnt++;
            else cnt2++;
        }
       
            
        return max(cnt,max(cnt2,(maxi)));
        
    }
        
};