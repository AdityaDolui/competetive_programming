class Solution {
public:

   int ans;
   void backtrack(int i,vector<int> & cookies, vector<int> & v){
       if(i==cookies.size()){
           ans=min(*max_element(v.begin(),v.end()),ans);
           return ;
       }

       for(int k=0;k<v.size();k++){
           v[k]+=cookies[i];
           backtrack(i+1,cookies,v);
            v[k]-=cookies[i];
       }
   }
    int distributeCookies(vector<int>& cookies, int k) {
        ans = INT_MAX;
        vector<int> buckets(k, 0);
        backtrack(0, cookies, buckets);
        return ans;
    }
};