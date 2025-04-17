class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
     return new ArrayList<>(  Arrays.stream(strs)
                .collect(Collectors.groupingBy(s->{
                    char[] arr=s.toCharArray();
                    Arrays.sort(arr);
                    return new String(arr);
                }))
                .values());
                
                
    }
}