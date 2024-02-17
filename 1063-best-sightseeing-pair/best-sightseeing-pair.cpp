class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans=0;
        int sum=values[0];
       

        for(int i=1;i<values.size();i++){
           ans=max(ans,sum+values[i]-i);
           sum=max(sum,values[i]+i);
        }
        return ans;
    }
};