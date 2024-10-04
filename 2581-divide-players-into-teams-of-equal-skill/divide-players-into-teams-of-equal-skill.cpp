class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long sum=0;
        vector<pair<int,int>> arr;
        int n=skill.size();
        sum= accumulate(skill.begin(),skill.end(),0);
       // if(sum&1)return -1;
        long long tar=sum/(n/2);
        unordered_map<int,int> map;
        int cnt=0;
        for(auto it:skill){
            if(map[tar-it]>0){
                cnt++;
                arr.push_back({it,(tar-it)});
                map[tar-it]--;
            }else{
                map[it]++;
            }
        }
        if(cnt!=(n/2))return -1;
        long long ans=0;
        for(auto it:arr){
            ans+=(it.first*it.second);
        }
        return ans;
    }
};