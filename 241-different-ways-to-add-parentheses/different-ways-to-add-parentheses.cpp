class Solution {
private:
   unordered_map<string,vector<int>> dp;
   vector<int> f(string str){
    if(dp.find(str)!=dp.end())return dp[str];

    vector<int> ans;
    for(int i=0;i<str.size();i++){
        if(str[i]=='-' || str[i]=='+' || str[i]=='*'){
        auto left =f(str.substr(0,i));
        auto right =f(str.substr(i+1));
        
        for(auto &l:left){
            for(auto &r:right){
                if(str[i] == '+')
                            ans.push_back(l + r);
                        if(str[i] == '-')
                            ans.push_back(l - r);
                        if(str[i] == '*')
                            ans.push_back(l * r);
            }
        }
        }
         
    }
    if(ans.empty()){
        ans.push_back(stoi(str));
    }
    return dp[str]=ans;
   }
public:


    // This is the main function that will be called to get all possible results
    vector<int> diffWaysToCompute(string exp) {
       return f(exp);
    }
};