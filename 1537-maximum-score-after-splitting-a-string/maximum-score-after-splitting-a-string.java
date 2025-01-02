class Solution {
    public int maxScore(String s) {
        int one =0,zero=0, currOne=0, currZero=0;
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='0')zero++;
            else one++;
        }

         for(int i=0;i<s.length()-1;i++){
            if(s.charAt(i)=='0')currZero++;
            else currOne++;

            ans=Math.max(ans,(currZero+(one-currOne)));
        
        }
        return ans;
    }
}