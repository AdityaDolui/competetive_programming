class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int cnt=0;
        unordered_map<int,int> map;

        for(auto it:nums){
            if(map[k-it]>0){
                cnt++;
                map[k-it]--;
            }else{
                map[it]++;
            }
        }
        return cnt;
    }
};