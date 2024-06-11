class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> map;
        vector<int> ans;
        for(auto it:arr1)map[it]++;

        for(auto it:arr2){
            int cnt=map[it];
            while(cnt--){
                ans.push_back(it);
            }
            map.erase(it);
        }
         for(auto it:map){
            int cnt=it.second;
            while(cnt--){
                ans.push_back(it.first);
            }
          
        }

        return ans;
    }
};