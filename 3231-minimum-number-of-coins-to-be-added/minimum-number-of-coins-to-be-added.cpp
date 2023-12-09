class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        int n=coins.size();
        map<int,int> map;
        for(auto it: coins)map[it]++;
        int ans=0;
        cout<<map.size();
        int last=0;
        auto i=map.begin();
        while(i!=map.end() && last<target){
            if(last<i->first-1){
                ans++;
                last+=last+1;
            }
            else{
                last+=(i->first)*i->second;
                i++;
            }
        }
        while(last<target){
            last+=last+1;
            ans++;
        }
        return ans;   
    }
};