class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long cnt=0;
        for(auto it:s)if(it==c)cnt++;
        return (cnt*(cnt+1))/2;
        
    }
};