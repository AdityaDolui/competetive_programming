class Solution {
    public String robotWithString(String s) {
         int[] freq = new int[26];

        for(char ch: s.toCharArray()){
            freq[ch-'a']++;
        }

        StringBuilder str=new StringBuilder();

       

        Stack<Character> st=new Stack<>();

        for(char ch: s.toCharArray()){

            st.push(ch);
            freq[ch-'a']--;

            while(!st.empty() && st.peek()<=smallestChar(freq)){
                str.append(st.pop());
            }
            
        }
         while(!st.isEmpty()){
                    str.append(st.pop());
                }

        return str.toString();
    }


     private char smallestChar(int[] freq) {
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                return (char) ('a' + i);
            }
        }
        return 'a';
    }
}