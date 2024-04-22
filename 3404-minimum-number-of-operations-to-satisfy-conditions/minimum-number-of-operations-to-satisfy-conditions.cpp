class Solution {
public:
    int ans = INT_MIN;
    int f(int i, int prev, map<pair<int, int>, int> &map,
          vector<vector<int>> &grid,  vector<vector<int>> &dp) {
        if (i >= grid[0].size()) {
            return 0;
        }

        int ans = INT_MAX;
        if(dp[i][prev]!=-1)return dp[i][prev];
        for (int k = 0; k <= 9; k++) {
            if (k != prev) {
                int curr =
                    (grid.size() - map[{i, k}]) + f(i + 1, k, map, grid,dp);
                cout << curr << " ";
                ans = min(ans, curr);
            }
        }

        return dp[i][prev]=ans;
    }
    int minimumOperations(vector<vector<int>>& grid) {
        map<pair<int, int>, int> map;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                map[{j, grid[i][j]}]++;
            }
        }
        vector<vector<int>> dp(grid[0].size(),vector<int>(11,-1));
        return f(0, 10, map, grid,dp);
    }
};