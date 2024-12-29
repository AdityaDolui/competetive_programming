class Solution {
    public int maxScoreSightseeingPair(int[] values) {
        int ans=0;
        int sum=values[0];

        for(int i=1;i<values.length;i++){
            ans=Math.max(ans,sum+values[i]-i);
            sum=Math.max(sum,values[i]+i);
        }
        return ans;
    }
}