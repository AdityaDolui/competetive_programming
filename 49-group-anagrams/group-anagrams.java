class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
    HashMap<String, List<String>> map =new HashMap<>();

    for(String str:strs){
        char[] charList=str.toCharArray();
        Arrays.sort(charList);

        String newStr= new String(charList);

        map.putIfAbsent(newStr,new ArrayList<>());
        map.get(newStr).add(str);
    }
    return new ArrayList<>(map.values());
    }
}