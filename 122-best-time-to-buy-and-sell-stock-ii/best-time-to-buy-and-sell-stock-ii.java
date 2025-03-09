class Solution {
    public int maxProfit(int[] prices) {
        boolean sell=false;
        int ans=0;
        int sellPrice=0;
        for(int i=0;i<prices.length-1;i++){
            if(prices[i]<prices[i+1]){
                if(!sell){
                    sell=true;
                    sellPrice=prices[i];
                }
            }
            else{
                    if(sell){
                        sell=false;
                        ans+=prices[i]-sellPrice;
                    }
                }
        }
        if(sell){
            ans+=prices[prices.length-1]-sellPrice;
            
        }
        return ans;
    }
}