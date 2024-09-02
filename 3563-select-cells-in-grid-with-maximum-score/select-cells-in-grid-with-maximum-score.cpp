class Solution {
public:
    map<pair<int,int>,int> dp;
    int f(int i,int mask,vector<vector<int>>& arr){
        if(i>=arr.size())return 0;

        
        if(dp[{i,mask}])return dp[{i,mask}];
        int ans=0;
        int row=arr[i][1];

        if(mask & (1<<row)){
            return dp[{i,mask}]= f(i+1,mask,arr);
        }
        else{
            ans+=arr[i][0];

            int k=i;
            while(k<arr.size() && arr[k][0]==arr[i][0])k++;

            int takeMask=mask | (1<<arr[i][1]);
            int take=ans+f(k,takeMask,arr);
            int nontake=+f(i+1,mask,arr);
            return dp[{i,mask}]= max(take,nontake);
        }
        
       
        
    }
    int maxScore(vector<vector<int>>& grid) {
        vector<vector<int>> arr;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                arr.push_back({grid[i][j],i,j});
            }
        }
        sort(arr.begin(),arr.end(),greater<vector<int>>());

        return f(0,0,arr);
    }
};