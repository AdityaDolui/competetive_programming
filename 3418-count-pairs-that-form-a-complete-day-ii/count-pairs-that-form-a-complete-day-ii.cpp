class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        unordered_map<int,int> map;

        long long ans=0;
        for(auto it:hours){
            if(!(it%24)){
                ans+=map[0];
                map[0]++;
            }else{

        
            if(map[24-(it%24)]>0){
                cout<<it<<" ";
                ans+=map[24-(it%24)];}
            map[(it%24)]++;
        }
        }
        for(auto it:map){
            cout<<it.first<<"-"<<it.second<<" || ";
        }
        return ans;
    }
};