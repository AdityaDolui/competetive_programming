class Solution {
public:
int cnt(int val){
    int ans=0;
    while(val){
        ans+=val%10;
        val=val/10;
    }
    return ans;
}
    int maximumSum(vector<int>& nums) {
        vector<int> arr=nums;
        unordered_map<int,priority_queue<int>> map;
        int i=0;
         
        for(auto &it:arr){
            it=cnt(it);
            map[it].push(nums[i]);
            i++;
            cout<<it<<" ";
        }
        int ans=0;
        for(auto &it:map){
           
            int first=it.second.top();
            it.second.pop();
            if(it.second.empty())continue;
            int second=it.second.top();
            ans=max(ans,(first+second));
        }
        if(ans==0)return -1;
        return ans;
    }
};