class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> set;
     int mini=INT_MAX;
     int maxi=0;
     for(auto it:nums){
        set.insert(it);
        mini=min(mini,it);
        maxi=max(maxi,it);
     }   
     int ans=0;
     for(int i=1;i<=maxi;i++){
        if(set.find(i)==set.end())return i;
     }
     return maxi+1;
    }
};