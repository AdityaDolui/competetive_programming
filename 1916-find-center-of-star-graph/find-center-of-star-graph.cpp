class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,unordered_set<int>>map;

        for(auto it:edges){
            map[it[0]].insert(it[1]);
            map[it[1]].insert(it[0]);
        }
        for(auto it:map)if(it.second.size()==edges.size())return it.first;
        return -1;
    }
};