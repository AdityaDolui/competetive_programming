class Solution {
public:
    int check(char ch,string s,int k){
        int ans=0;

        int l=0,h=0;
        while(h<s.length()){
            if(k<0){
                while(l<=h && k<0){
                    if(s[l]!=ch)k++;
                    l++;
                }
            }
            if(s[h]!=ch)k--;
            if(k>=0){
            ans=max(ans,(h-l+1));}
            h++;
        }
        return ans;

    }    
    int characterReplacement(string s, int k) {
        unordered_set<int> set;
        for(auto it:s)set.insert(it);

        int ans=0;

        for(auto it:set)ans=max(ans,check(it,s,k));

        return ans;
    }
};