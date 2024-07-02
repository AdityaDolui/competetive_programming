class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>map1;
        for(auto it:nums1)map1[it]++;
       //  for(auto it:nums2)map2[it]++;
    vector<int> ans;
         for(auto it:nums2){
            if(map1[it]>0){ans.push_back(it);
            map1[it]--;
            }
         }
         return ans;
    }
};