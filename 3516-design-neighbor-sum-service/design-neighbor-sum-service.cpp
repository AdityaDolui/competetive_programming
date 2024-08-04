class neighborSum {
public:
    vector<vector<int>> grid;
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    
     int dxx[4]={-1,1,-1,1};
    int dyy[4]={-1,1,1,-1};
    neighborSum(vector<vector<int>>& arr) {
        grid=arr;
    }
    
    int adjacentSum(int value) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==value){
                    for(int k=0;k<4;k++){
                        int x=i+dx[k];
                        int y=j+dy[k];
                        if(x>=0 && x<grid.size() && y>=0 && y<grid[0].size()){
                            ans+=grid[x][y];
                        }
                    }
                    return ans;
                }
            }
        }
        return ans;
    }
    
    int diagonalSum(int value) {
          int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==value){
                    for(int k=0;k<4;k++){
                        int x=i+dxx[k];
                        int y=j+dyy[k];
                        if(x>=0 && x<grid.size() && y>=0 && y<grid[0].size()){
                            ans+=grid[x][y];
                        }
                    }
                    return ans;
                }
            }
        }
        return ans;
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */