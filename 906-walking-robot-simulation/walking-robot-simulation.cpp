#pragma GCC optimize("03", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // n, e, s, w
        pair<int, int> pos = {0, 0};
        int dircode = 0;
        int ans = 0;

        unordered_map<int, vector<int>> xAxisObs;
        unordered_map<int, vector<int>> yAxisObs;

        for (const auto &obstacle : obstacles) {
            int x = obstacle[0];
            int y = obstacle[1];
            xAxisObs[x].push_back(y);
            yAxisObs[y].push_back(x);
        }

        for (auto &element : xAxisObs) {
            sort(element.second.begin(), element.second.end());
        }
        for (auto &element : yAxisObs) {
            sort(element.second.begin(), element.second.end());
        }

        for (int command : commands) {
            if (command == -2) {
                dircode = (dircode + 3) % 4;
            } else if (command == -1) {
                dircode = (dircode + 1) % 4;
            } else {
                int k = command;
                int xPos = pos.first;
                int yPos = pos.second;

                if (dircode == 0) {
                    int yGoal = yPos + k;
                    auto it = lower_bound(xAxisObs[xPos].begin(), xAxisObs[xPos].end(), yPos + 1);
                    if (it != xAxisObs[xPos].end() && *it <= yGoal) {
                        yPos = *it - 1;
                    } else {
                        yPos = yGoal;
                    }
                } else if (dircode == 1) {
                    int xGoal = xPos + k;
                    auto it = lower_bound(yAxisObs[yPos].begin(), yAxisObs[yPos].end(), xPos + 1);
                    if (it != yAxisObs[yPos].end() && *it <= xGoal) {
                        xPos = *it - 1;
                    } else {
                        xPos = xGoal;
                    }
                } else if (dircode == 2) {
                    int yGoal = yPos - k;
                    auto it = upper_bound(xAxisObs[xPos].begin(), xAxisObs[xPos].end(), yPos - 1);
                    if (it != xAxisObs[xPos].begin() && *(--it) >= yGoal) {
                        yPos = *it + 1;
                    } else {
                        yPos = yGoal;
                    }
                } else if (dircode == 3) {
                    int xGoal = xPos - k;
                    auto it = upper_bound(yAxisObs[yPos].begin(), yAxisObs[yPos].end(), xPos - 1);
                    if (it != yAxisObs[yPos].begin() && *(--it) >= xGoal) {
                        xPos = *it + 1;
                    } else {
                        xPos = xGoal;
                    }
                }

                pos.first = xPos;
                pos.second = yPos;
                ans = max(ans, pos.first * pos.first + pos.second * pos.second);
            }
        }

        return ans;
    }
};