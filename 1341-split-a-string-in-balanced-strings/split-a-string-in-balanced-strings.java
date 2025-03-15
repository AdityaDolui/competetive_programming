class Solution {
    public int balancedStringSplit(String s) {
      int ans=0;
      int bal=0;
      for(char ch:s.toCharArray()){
        if(ch=='L')bal++;
        else bal--;
        if(bal==0)ans++;
      }

      return ans;
    }
}