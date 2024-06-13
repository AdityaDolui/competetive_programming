class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n=s.length();
        if(n<k) return s;
       stack<pair<char,int>> st;
       for(int i=0;i<n;i++){
        if(st.empty() || s[i]!=st.top().first)st.push({s[i],1});
        else{
            auto it=st.top();
            st.pop();
            if(it.second+1!=k)
            st.push({s[i],it.second+1});
            
        }
       }

       string ans="";
       while(!st.empty()){
        auto it=st.top();
        st.pop();
        while(it.second--){
            ans+=it.first;
        }
       }
       reverse(ans.begin(),ans.end());
       return ans;
    }
};