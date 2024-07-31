class Solution {
public:
int width;
    int f(int i,vector<vector<int>>& books,int remainW,int height,vector<vector<int>>& dp){
        if(i>=books.size())return height;
    int heig=books[i][1];
    int widt=books[i][0];
    if(dp[i][remainW]!=-1)return dp[i][remainW];

    int take=INT_MAX,nontake=INT_MAX;

    nontake=height+f(i+1,books,width-widt,heig,dp);
    if(remainW>=widt){
        take=f(i+1,books,remainW-widt,max(height,heig),dp);
    }
    return dp[i][remainW]=min(take,nontake);

    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        width=shelfWidth;
        int n=books.size();
        vector<vector<int>> dp(n,vector<int>(shelfWidth+1,-1));
        return f(0,books,width,0,dp);

    }};