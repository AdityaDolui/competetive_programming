class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        
        
        int cnt=0;
        if(grid[0][0]=='B')cnt++;
        if(grid[0][1]=='B')cnt++;
        if(grid[1][0]=='B')cnt++;
        if(grid[1][1]=='B')cnt++;
        cout<<cnt<<" ";
        if(cnt<=1)return true;
        cnt=0;
        if(grid[0][1]=='B')cnt++;
        if(grid[1][1]=='B')cnt++;
        if(grid[0][2]=='B')cnt++;
        if(grid[1][2]=='B')cnt++;
         cout<<cnt<<" ";
         if(cnt<=1)return true;
        cnt=0;
        if(grid[1][0]=='B')cnt++;
        if(grid[1][1]=='B')cnt++;
        if(grid[2][0]=='B')cnt++;
        if(grid[2][1]=='B')cnt++;
         cout<<cnt<<" ";
         if(cnt<=1)return true;
        cnt=0;
        if(grid[1][1]=='B')cnt++;
        if(grid[2][1]=='B')cnt++;
        if(grid[1][2]=='B')cnt++;
        if(grid[2][2]=='B')cnt++;
         cout<<cnt<<" ";
         if(cnt<=1)return true;



         cnt=0;
        if(grid[0][0]=='W')cnt++;
        if(grid[0][1]=='W')cnt++;
        if(grid[1][0]=='W')cnt++;
        if(grid[1][1]=='W')cnt++;
        cout<<cnt<<" ";
        if(cnt<=1)return true;
        cnt=0;
        if(grid[0][1]=='W')cnt++;
        if(grid[1][1]=='W')cnt++;
        if(grid[0][2]=='W')cnt++;
        if(grid[1][2]=='W')cnt++;
         cout<<cnt<<" ";
         if(cnt<=1)return true;
        cnt=0;
        if(grid[1][0]=='W')cnt++;
        if(grid[1][1]=='W')cnt++;
        if(grid[2][0]=='W')cnt++;
        if(grid[2][1]=='W')cnt++;
         cout<<cnt<<" ";
         if(cnt<=1)return true;
        cnt=0;
        if(grid[1][1]=='W')cnt++;
        if(grid[2][1]=='W')cnt++;
        if(grid[1][2]=='W')cnt++;
        if(grid[2][2]=='W')cnt++;
         cout<<cnt<<" ";
         if(cnt<=1)return true;
         return false;
    }
};