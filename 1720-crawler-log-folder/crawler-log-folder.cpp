class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans=0;
        for(auto it:logs){
           if(it.length()==3 && it=="../" && ans)ans--;
            else if(it[it.length()-2]!='.')ans++;
        }
        return ans;
    }
};