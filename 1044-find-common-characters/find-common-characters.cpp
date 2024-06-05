class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        unordered_map<char,int> map;
        for(auto it:words[0])map[it]++;
        
        for(auto &it:words){
          //  unordered_map<char,int> curr;
            unordered_map<char,int> newit;
            for(auto i:it){
                if(map[i]>0){
                    map[i]--;
                    newit[i]++;
                }
            }
            map=newit;
            
          
        }
        
        vector<string> ans;
        for(auto &it:map){
            while(it.second>0){
                string s="";
                s+=it.first;
                ans.push_back(s);
                it.second--;
            }
        }
        
        return ans;
    }
};