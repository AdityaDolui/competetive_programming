class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ans;
        unordered_map<string,int> map,map2;
        string word;

        istringstream iss(s1);
        while(iss>>word){
            map[word]++;
       
        }  
         istringstream is(s2);
        while(is >> word){
           map2[word]++;
        }


         for(auto it:map){
            if(it.second==1){
            if(map2.find(it.first)==map2.end())ans.push_back(it.first);
            }
         }
         for(auto it:map2){
            if(it.second==1){
            if(map.find(it.first)==map.end())ans.push_back(it.first);
            }
         }
   
        return ans;

    }
};