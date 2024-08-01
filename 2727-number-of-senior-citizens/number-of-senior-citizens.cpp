class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans=0;
        for(auto it:details){
            string sub=it.substr(11,2);
            int age=stoi(sub);
            if(age>60)ans++;
        }
        return ans;
    }
};