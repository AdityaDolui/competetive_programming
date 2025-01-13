class Solution {
    public boolean canBeValid(String s, String locked) {
     boolean result =true;

     int mini=0, maxi=0;
     if((s.length()&1)==1)return false;

     for(int i=0;i<s.length();i++){

        if(s.charAt(i)=='(' || locked.charAt(i)=='0')maxi++;
        else{
            maxi--;
        };
        if(s.charAt(i)==')' || locked.charAt(i)=='0')mini--;
        else{
            mini++;
        }

        if( maxi<0)return false;
        mini=Math.max(mini,0);
      
     }   
       
       return mini==0;
    }
}