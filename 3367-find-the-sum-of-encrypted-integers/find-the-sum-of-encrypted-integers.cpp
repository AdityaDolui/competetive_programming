class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int ans=0;
        for(auto it:nums){
            int maxi=0;
            int cnt=0;
            while(it){
                maxi=max(maxi,it%10);
                it=it/10;
                cnt++;
            }
            int num=0;
            while(cnt--){
                num=num*10+maxi;
            }
            ans+=num;

        }
        return ans;
    }
};