class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=numBottles;
        int empty=0;
        while(numBottles){
             empty+=numBottles;
            numBottles=empty/numExchange;
            empty=empty%numExchange;
            ans+=numBottles;
        }
        return ans;
    }
};