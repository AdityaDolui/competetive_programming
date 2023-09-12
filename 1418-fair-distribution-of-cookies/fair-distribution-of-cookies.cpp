class Solution {
public:

   int ans;
   void backtrack(int i,vector<int> & cookies, vector<int> & v, int sum){
       if(i==cookies.size()){
           ans=min(sum,ans);
           return ;
       }

       for(int k=0;k<v.size();k++){
           v[k]+=cookies[i];
           backtrack(i+1,cookies,v,max(v[k],sum));
            v[k]-=cookies[i];
       }
   }
    int distributeCookies(vector<int>& cookies, int k) {
        ans = INT_MAX;
        vector<int> buckets(k, 0);
        backtrack(0, cookies, buckets, 0);
        return ans;
    }
};