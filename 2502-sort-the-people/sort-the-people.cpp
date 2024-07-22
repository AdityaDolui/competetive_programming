class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<string> ans;
        vector<pair<int,string >> p;
        for(int i=0;i<names.size();i++){
            p.push_back({heights[i],names[i]});
        }
        sort(p.begin(),p.end(),greater());
        for(auto it:p)ans.push_back(it.second);
        return ans;
    }
};