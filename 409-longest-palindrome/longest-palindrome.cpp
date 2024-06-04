class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> map;
        for(auto it:s)map[it]++;

        int ans=0;
        for(auto it:map){
            ans+=(it.second/2)*2;
        }
        if(ans!=s.length())ans++;
        return ans;
    }
};