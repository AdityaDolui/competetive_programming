class Solution {
public:
int mod=(1e9+7);
 
    int f(int n,vector<int>& rollMax,int prev,int count,  vector<vector<vector<int>>> & dp){
        if(n==0){
            return 1;
            }

        if(dp[n][prev][count]!=-1)return dp[n][prev][count];
        long long ans=0;
        for(int i=1;i<=6;i++){

            int cnt=i==prev?count+1:1;
           
           if(rollMax[i-1]<cnt)continue;

              
               ans=(ans%mod + f(n-1,rollMax,i,cnt,dp)%mod)%mod;
                
            }
        return  dp[n][prev][count]= ans%mod;
    }
    int dieSimulator(int n, vector<int>& rollMax) {
        vector<vector<vector<int>>> dp (n+1,vector<vector<int>>(8,vector<int>(16,-1)));
       return f(n,rollMax,0,0,dp)%mod;
        
     
    }
};