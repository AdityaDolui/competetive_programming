class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long cnt=0;
        for(auto it:s)if(it==c)cnt++;

        long long ans=0;
        ans=(cnt*(cnt+1))/2;
        return ans;
    }
};