class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ans;
        unordered_map<string,int> map;
        string word;

        istringstream iss(s1);
        while(iss>>word){
            map[word]++;
       
        }  
         istringstream is(s2);
        while(is >> word){
           map[word]++;
        }


         for(auto it:map){
            if(it.second==1)ans.push_back(it.first); }
           
        
        return ans;

    }
};