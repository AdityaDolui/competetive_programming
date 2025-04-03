class Solution {
    public void reverseString(char[] s) {
       IntStream.range(0,s.length/2)
            .forEach(i->{
                char temp=s[i];
                s[i]= s[s.length-1-i];
                s[s.length-1-i]=temp;
                
            });
           
    }
}