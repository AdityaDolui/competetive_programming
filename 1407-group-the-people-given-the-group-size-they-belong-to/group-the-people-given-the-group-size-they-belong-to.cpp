class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        int n=groupSizes.size();
        unordered_map<int,vector<int>> map;
        for(int i=0;i<n;i++){
            map[groupSizes[i]].push_back(i);
        }
        for(auto it:map){
            vector<int> vec=it.second;
            int div=it.first;
            int cnt=0;
            vector<int> temp;
            for(auto num:vec){
                    temp.push_back(num);
                    cnt++;
                    if(cnt==div){
                        ans.push_back(temp);
                        temp.clear();
                        cnt=0;
                    }
            }
        }
        return ans;
    }
};