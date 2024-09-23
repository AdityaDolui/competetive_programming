class Solution {
public:
int ans=INT_MAX;
    int min(int a,int b){
        return a<b?a:b;
    }
    int f(int i,string &s,unordered_set<string> &set,vector<int>& dp){
        if(i>=s.size()){
            return 0;
        }
        if(dp[i]!=-1)return dp[i];
    int cnt=INT_MAX;
        string str="";
        for(int k=i;k<s.length();k++){
            str+=s[k];
            if(set.find(str)!=set.end()){             
                cnt=min(cnt,f(k+1,s,set,dp));                
            }    
        }
        return dp[i]= min(cnt,1+f(i+1,s,set,dp));
       
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> set;
        for(auto it:dictionary){
            set.insert(it);
        }
       vector<int> dp(s.length(),-1);
        return f(0,s,set,dp);

    }
};