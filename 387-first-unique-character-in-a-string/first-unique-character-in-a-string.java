class Solution {
    public int firstUniqChar(String s) {

       return IntStream.range(0,s.length())
                        .boxed()
                        .collect(Collectors.groupingBy(i->s.charAt(i), LinkedHashMap::new,Collectors.toList() ))
                        .entrySet()
                        .stream()
                        .filter(entry->entry.getValue().size()==1)
                        .flatMap(entry->entry.getValue().stream())
                        .findFirst()
                        .orElse(-1);
        
        
    }
}