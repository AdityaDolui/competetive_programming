class Solution {
    public String clearDigits(String s) {
        Stack<Character> st=new Stack<>();

        for(char ch:s.toCharArray()){
                if(Character.isDigit(ch)){
                    if(st.size()>0)st.pop();
                }else{
                    st.push(ch);
                }
        }
        
        if(st.isEmpty())return "";

        String ans="";
        while(!st.isEmpty()){
            ans=st.peek()+ans;
            st.pop();
        }
        return ans;
    }
}