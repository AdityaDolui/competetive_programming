class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int window=0;
        for(auto it:nums)if(it&1)window++;
        int n=nums.size();
        if(window==n)return 0;
        int curr=0;
        cout<<window<<" ";
        for(int i=0;i<window;i++){
            if(nums[i]&1)curr++;
        }
        int ans=window-curr;
        if(curr==window)return 0;
        int  j=(window)%n;

        for(int i=1;i<n;i++){
           
            j=j%n;
            if(nums[i-1]&1)curr--;
            if(nums[j++]&1)curr++;

            ans=min(ans,(window-curr));
            cout<<curr<<" ";
        }
        return ans;
    }
};