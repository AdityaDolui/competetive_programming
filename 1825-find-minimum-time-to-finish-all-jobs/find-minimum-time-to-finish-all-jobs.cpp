class Solution {
public:
int ans;
void f(int i,vector<int> & B,vector<int> &temp){
         
        if(i==B.size()){ 
           ans=min(*max_element(temp.begin(),temp.end()),ans);
           return ;
        }
      if(*max_element(temp.begin(),temp.end())>=ans)return;
      for(int j=0;j<temp.size();j++){
           if(j > 0 and temp[j] >= temp[j - 1])continue;
          temp[j]+=B[i];
          f(i+1,B,temp);
          temp[j]-=B[i];
      }
      return ;
    }
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int N=jobs.size();
        ans=INT_MAX;
        sort(jobs.begin(),jobs.end(),greater<int>());
        vector<int> temp(k,0);
     //   vector<vector<int>> dp(N+1,vector<int>(k+1,-1));
         f(0,jobs,temp);
         return ans;
    }
};