class Solution {
public:
long long check(vector<int> &set){
    long long ans=0;
    int prev=0;
    for(auto it:set ){
        if(it>prev)ans+=it-prev;
        prev=it;
    }
return ans;
}
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
    long long ans=0;
        int prev=-1;
        int maxi=0;
        vector<int> set;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target[i]){
                ans+=check(set);
                set.clear();
            }
           else if(nums[i]>target[i]){
                if(!prev || prev==-1){
                    set.push_back(abs(nums[i]-target[i]));
                   
                    prev=0;
                }else{
                    prev=0;
                    ans+=check(set);
                    
                    cout<<"here";
                    set.clear();
                    set.push_back(abs(nums[i]-target[i]));
                       
                }
            }else{
                if(prev==0){
                    prev=1;
                    cout<<"here";
                    ans+=check(set);
                    
                    set.clear();
                    set.push_back(abs(nums[i]-target[i]));
                   
                }else{
                     set.push_back(abs(nums[i]-target[i]));
                     prev=1;
                }
            }
        }
       
    ans+=check(set);
        return ans;
    }
};