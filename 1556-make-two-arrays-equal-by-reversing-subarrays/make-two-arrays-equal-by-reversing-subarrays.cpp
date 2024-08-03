class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> map;
        for(auto it:target)map[it]++;

        for(auto it:arr){
            if(map.find(it)==map.end())return false;
            map[it]--;
            if(map[it]==0)map.erase(it);
        }
        return true;
    }
};