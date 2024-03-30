class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int ans=0;

        int l=0,h=0;
        while(h<nums.size()){
            if(k<0){
                while(l<=h && k<0){
                    if(nums[l]!=1)k++;
                    l++;
                }
            }
            if(nums[h]!=1)k--;
            if(k>=0){
            ans=max(ans,(h-l+1));}
            h++;
        }
        return ans;

    
    }
};