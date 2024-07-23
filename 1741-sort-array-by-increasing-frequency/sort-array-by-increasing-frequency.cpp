class Solution {
public:
    static bool comp(pair<int,int>a, pair<int,int> b){
        if(a.second==b.second)return a.first>b.first;
        return a.second<b.second;
    }
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
        } 
        vector<pair<int,int>> v;
        for(auto it:map){
            v.push_back({it.first,it.second});
        }
        sort(v.begin(),v.end(),comp);
        vector<int> ans;
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].second;j++){
            ans.push_back(v[i].first);
        }
    }
    return ans;
    }
};