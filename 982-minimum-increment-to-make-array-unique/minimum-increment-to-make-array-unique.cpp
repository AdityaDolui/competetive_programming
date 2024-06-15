class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        map<int,int> map;
        for(auto it:nums)map[it]++;
    int ans=0;
        for(auto it=map.begin();it!=map.end();it++){
            int cost=it->second-1;
            
            if(cost){
                ans+=cost;
                map[it->first+1]+=cost;
            }
        }
        return ans;
    }
};