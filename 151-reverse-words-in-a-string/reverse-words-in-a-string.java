class Solution {
    public String reverseWords(String s) {
     //   String[] arr=s.split(" ");
         List<String> list = new ArrayList<>(Arrays.asList(s.split(" ")));
        Collections.reverse(list);
          
          list= list.stream()
                    .filter(str-> !str.trim().isEmpty())
                    .toList();
        //    System.out.println(list.toString());
         String ans=String.join(" ",list);
         return ans;
    }
}