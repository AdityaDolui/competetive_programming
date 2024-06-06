class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size()%groupSize)return 0;
        unordered_map<int,int> map;
        sort(hand.begin(),hand.end());
        for(auto it:hand)map[it]++;
        for(auto it:hand){
            if(map[it]>0){          
                for(int i=it;i<it+groupSize;i++){
                    if(map[i]<=0)return 0;
                    else map[i]--;
                }
            }
        }
        return 1;
    }
};