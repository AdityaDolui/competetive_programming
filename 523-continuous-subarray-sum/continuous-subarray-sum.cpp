class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map;
       //unordered_set<int> map;
        int n=nums.size();
        if(n==1 && nums[0]==0)return false;
        
        int sum=0;
       map[0]=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int rem=sum%k;
            
             if(map.find(rem)==map.end()){
                 map[rem]=i+1;
             }

           else{
                if(map[rem]<i)
                return true;
            }
            
           
        }
        return false;
    }
};