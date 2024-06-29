class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long ans=0;
        unordered_map<int,int> map;
        vector<pair<int,int>> count(n);
        for(int i=0;i<n;i++){
            count[i].second=i;
        }

        for(auto it:roads){
            count[it[0]].first++;
            count[it[1]].first++;
        }
        sort(count.begin(),count.end());

        for(int i=1;i<=n;i++){
            map[count[i-1].second]=i;
        }
        for(auto it:roads){
            ans+=map[it[0]]+map[it[1]];
        }
        return ans;

    }
};