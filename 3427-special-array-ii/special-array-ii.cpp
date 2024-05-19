class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
       vector<int> ans;
        ans.push_back(-1);
            
        int  first =nums[0]&1;
       
        int second=-1;
        if(nums.size()>1)second=nums[1]&1;
        
        
        if(first==second){
           
            ans.push_back(0);
        }else ans.push_back(-1);
          
        for(int i=2;i<nums.size();i++){
            swap(first,second);
            second=nums[i]&1;
            if(first==second){
                // cout<<20;
                ans.push_back(i-1);
            }else ans.push_back(ans.back());
            
                
        }
            
        
        
    // for(auto it:ans)cout<<it<<" ";
    // cout<<endl;
    vector<bool> res;
    for(auto it :queries){
        if(ans[it[1]]<it[0])res.push_back(true);
        else res.push_back(false);
    }
            
         
         return res;
    }
};