class Solution {
    public boolean isPalindrome(int x) {
        if(x<0)return false;
       String str=String.valueOf(x);
       String reverse=new StringBuilder(str).reverse().toString();
     //  System.out.println(str);
       
       return str.equals(reverse) ? true: false;
    }
}