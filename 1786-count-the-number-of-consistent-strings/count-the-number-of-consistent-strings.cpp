class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<int> set;
        for(auto it:allowed)set.insert(it);
        int ans=0;
        for(auto it:words){
            bool flag=true;
            for(auto iit:it ){
                if(set.find(iit)==set.end()){
                    flag =false;
                    break;
                }
            }
            if(flag)ans++;
        }
        return ans;
    }
};