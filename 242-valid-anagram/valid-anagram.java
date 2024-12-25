class Solution {
    public boolean isAnagram(String s, String t) {
        
        char[] charArrayS=s.toCharArray();
        Arrays.sort(charArrayS);
        String newS=new String(charArrayS);

        char[] charArrayT=t.toCharArray();
        Arrays.sort(charArrayT);
        String newT=new String(charArrayT);

        return newS.equals(newT);

    }
}