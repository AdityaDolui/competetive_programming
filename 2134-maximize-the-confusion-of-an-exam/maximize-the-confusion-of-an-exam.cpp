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
    int maxConsecutiveAnswers(string answerKey, int k) {
        
        int ans=0;
        ans=check('F',answerKey,k);
        ans=max(ans,check('T',answerKey,k));

        return ans;
    }
};