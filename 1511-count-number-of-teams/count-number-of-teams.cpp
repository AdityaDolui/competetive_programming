class Solution {
public:
int dp[1002][1002][4];
   
int increase(vector<int>& ratings,int i,int prev,int cnt){
    if(cnt==3){
        return 1;
    }
    if(i==ratings.size()){
        return 0;
    }
    if(dp[i][prev+1][cnt]!=-1)return dp[i][prev+1][cnt];
    int nontake=increase(ratings,i+1,prev,cnt);
    int take=0;
    if(prev==-1 || ratings[prev]>ratings[i]){
        take=increase(ratings,i+1,i,cnt+1);
    }
    return dp[i][prev+1][cnt]=take+nontake;
}
int dicrease(vector<int>& ratings,int i,int prev,int cnt){
    if(cnt==3){
        return 1;
    }
    if(i==ratings.size()){
        return 0;
    }
    if(dp[i][prev+1][cnt]!=-1)return dp[i][prev+1][cnt];
    int nontake=dicrease(ratings,i+1,prev,cnt);
    int take=0;
    if(prev==-1 || ratings[prev]<ratings[i]){
        take=dicrease(ratings,i+1,i,cnt+1);
    }
    return dp[i][prev+1][cnt]=take+nontake;
}
    int numTeams(vector<int>& ratings) {
          memset(dp, -1, sizeof(dp));
       // vector<vector<vector<int>>> dp(ratings.size(),vector<vector<int>>(ratings.size()+1,vector<int>(3,-1)));
        int increases=increase(ratings,0,-1,0);
        memset(dp,-1,sizeof(dp));
         //vector<vector<vector<int>>> dp1(ratings.size(),vector<vector<int>>(ratings.size()+1,vector<int>(3,-1)));
        int dicreases=dicrease(ratings,0,-1,0);

        return increases+dicreases; 
    }
};