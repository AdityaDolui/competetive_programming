class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
         sort(nums.begin() , nums.end()); 
        int n=nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1])continue;
                int first=nums[i];
                int j=i+1,k=n-1;
                while(j<k){
                    if((first+nums[j]+nums[k])<0) j++;
                    else if((first+nums[j]+nums[k])>0)k--;
                    else {
                        vector<int> temp;
                        temp.push_back(first);
                         temp.push_back(nums[j]);
                         temp.push_back(nums[k]);
                        ans.push_back(temp);
                        while(j<k && nums[j]==nums[j+1])j++;
                        while(j<k && nums[k]==nums[k-1])k--;

                        j++;
                        k--;
                                            }
                }
                while(i+1<n && nums[i]==nums[i+1])i++;
        }
        return ans;
    }
};