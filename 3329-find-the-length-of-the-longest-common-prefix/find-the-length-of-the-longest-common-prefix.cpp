class Solution {
public:
    int max(int a,int b){
        return a>b?a:b;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int ans=0;

    vector<string> str1;
    for(auto it:arr1)str1.push_back(to_string(it));

    unordered_set<string> set;

    for(auto it :str1){
        string ss="";
        for(int i=0;i<it.length();i++){
            ss+=it[i];
            set.insert(ss);
        }
    }
    
    vector<string> str2;
    for(auto it:arr2)str2.push_back(to_string(it));

        for(auto it:str2){
           string ss="";
           for(int i=0;i<it.size();i++){
            ss+=it[i];
            if(set.find(ss)!=set.end())ans=max(ans,ss.length());
           }
          
        }
        return ans;
    }
};