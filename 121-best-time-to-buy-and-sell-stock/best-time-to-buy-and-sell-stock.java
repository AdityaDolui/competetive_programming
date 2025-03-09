class Solution {
    public int maxProfit(int[] prices) {
         int mini=prices[0];
        int maxi=0,cost=0;

        for(int i=1;i<prices.length;i++){
            cost=prices[i]-mini;
            maxi=Math.max(maxi,cost);
            mini=Math.min(mini,prices[i]);
        }
        return maxi;
    }
}