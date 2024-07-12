class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        int n=word.length();
        int ans=0;
        if(n==2){
            if(abs(word[0]-word[1])<=1)return 1;
        }
        for(int i=1;i<n;i++){
            if(abs(word[i-1]-word[i])<=1){
                word[i]='A';
                ans++;
            }
        }
        return ans;
    }
};