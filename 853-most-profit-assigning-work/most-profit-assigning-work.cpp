class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        // n^m time complexity  
        int ans=0;
        int m=difficulty.size();
        for(auto it:worker){
            int maxi=0;
            for(int i=0;i<m;i++){
                if(difficulty[i]<=it){
                    maxi=max(maxi,profit[i]);
                }
            }
            ans+=maxi;
        }
        return ans;
    }
};