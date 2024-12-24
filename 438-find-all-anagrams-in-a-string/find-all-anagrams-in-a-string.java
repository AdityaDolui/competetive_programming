class Solution {
    public List<Integer> findAnagrams(String s, String p) {
         List<Integer> ans=new ArrayList<>();

        char[] charP=p.toCharArray();
        Arrays.sort(charP);

        //p= Arrays.toString(charP);
        String newP=new String(charP);
     //   System.out.println(Arrays.toString(charP));
        for(int i=0;i<=(s.length()-p.length());i++){
            String str=s.substring(i,i+p.length());
            System.out.println(i);
            char[] charStr=str.toCharArray();
            Arrays.sort(charStr);
           // str= Arrays.toString(charStr);
            String newStr=new String(charStr);
            if(newStr.equals(newP)) {
                System.out.println("Hi");
                ans.add(i);
            }
        }

return ans;
   // ans.forEach(System.out::println);
    }
}