class Solution {
public:
    bool isSubstringPresent(string s) {
        
        unordered_set<string> set;
        for(int i=0;i<s.length()-1;i++){
            string temp=s.substr(i,2);
            set.insert(temp);

        }
       
        string str=s;
        reverse(str.begin(),str.end());

       for(int i=0;i<s.length()-1;i++){
            string temp=str.substr(i,2);
            if(set.find(temp)!=set.end())return 1;

        }
        return 0;
    }
};