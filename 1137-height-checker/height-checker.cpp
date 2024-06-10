class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> arr;
        arr=heights;
        sort(arr.begin(),arr.end());
        int ans=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]!=heights[i])ans++;
        }
        return ans;
    }
};