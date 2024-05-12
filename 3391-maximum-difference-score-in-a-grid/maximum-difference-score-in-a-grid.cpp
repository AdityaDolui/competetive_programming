class Solution {
public:

    int maxScore(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> arr(n,vector<int>(m,0));
        int ans=INT_MIN;
        int mini=INT_MAX;
        for(int i=0;i<m;i++){
            mini=min(mini,grid[0][i]);
            
            if(grid[0][i]!=mini)
            ans=max(ans,(grid[0][i]-mini));
            arr[0][i]=mini;
}
        mini=INT_MAX;
         for(int i=0;i<n;i++){
            mini=min(mini,grid[i][0]);
            
             if(grid[i][0]!=mini)
             ans=max(ans,(grid[i][0]-mini));
            arr[i][0]=mini;
}
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                int val=min(arr[i-1][j],arr[i][j-1]);
                ans=max(ans,(grid[i][j]-val));
                arr[i][j]=min(val,grid[i][j]);
            }
        }
       
        return ans;
    }
};