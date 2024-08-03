class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> map(1000+1);
        for(auto it:target)map[it]++;
        for(auto it:arr){
            if(map[it]<=0)return false;
            map[it]--;
        }
        return true;
    }
};