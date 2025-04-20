class Solution {
    public int countWords(String[] words1, String[] words2) {
        Set<String> set1=
                        Arrays.stream(words1)
                                .collect(Collectors.groupingBy(s->s, Collectors.counting()))
                                .entrySet()
                                .stream()
                                .filter(s->s.getValue()==1)
                                .map(s->s.getKey())
                                .collect(Collectors.toSet());

         Set<String> set2=Arrays.stream(words2)
                                .collect(Collectors.groupingBy(s->s, Collectors.counting()))
                                .entrySet()
                                .stream()
                                .filter(s->s.getValue()==1)
                                .map(s->s.getKey())
                                .collect(Collectors.toSet());

      set1.retainAll(set2);
      System.out.println(set1);
      return set1.size();
    }
}