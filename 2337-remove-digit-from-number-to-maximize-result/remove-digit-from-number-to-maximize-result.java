class Solution {
    public String removeDigit(String number, char digit) {
        
       
         int i=number.indexOf(digit);
     
       String ans= number.substring(0,i)+number.substring(i+1);
           i=number.indexOf(digit,i+1);
       while(i!=-1){
        String s1=number.substring(0,i)+number.substring(i+1);
        i=number.indexOf(digit,i+1);
        if(ans.compareTo(s1)<0)ans=s1;
       }
      return ans;
    }
}