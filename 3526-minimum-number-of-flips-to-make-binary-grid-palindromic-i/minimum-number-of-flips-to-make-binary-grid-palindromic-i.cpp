class Solution {
public:
    int check(vector<int> & arr){
        int n=arr.size();
        int ans=0;
        for(int i=0;i<n/2;i++){
            if(arr[i]!=arr[n-1-i])ans++;
        }
        return ans;
    }
    int minFlips(vector<vector<int>>& grid) {
        int col=0,row=0;
        for(int i=0;i<grid.size();i++){
            col+=check(grid[i]);
            
}
        for(int i=0;i<grid[0].size();i++){
            vector<int> arr;
            
            for(int j=0;j<grid.size();j++){
                arr.push_back(grid[j][i]);
            }
            row+=check(arr);
        }
        return min(col,row);
    }
};