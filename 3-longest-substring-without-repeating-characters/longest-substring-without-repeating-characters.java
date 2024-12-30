class Solution {
    public int lengthOfLongestSubstring(String s) {
        int ans=0;

        HashSet<Character> set=new HashSet<>();

        int l=0,h=0;
        while(h<s.length()){
            if(set.contains(s.charAt(h))){
                while(true && set.size()>0){
                    if(s.charAt(l)==s.charAt(h)){
                        l++;
                        break;}
                    set.remove(s.charAt(l));
                    l++;

                }
            }
            else set.add(s.charAt(h));
            ans=Math.max(ans,set.size());
            h++;
        }

        return ans;
    }
}