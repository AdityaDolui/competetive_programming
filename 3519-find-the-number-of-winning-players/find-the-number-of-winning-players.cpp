class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        vector<unordered_map<int,int>> arr(n);
        
        for(int i=0;i<pick.size();i++ ){
            arr[pick[i][0]][pick[i][1]]++;
        }
        int ans=0;
        for(int i=0;i<n;i++){
          
            for(auto it:arr[i]){
                if(it.second>i){
                    ans++;
                    break;
                }
            }
}
        return ans;
    }
};