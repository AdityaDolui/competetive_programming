class Solution {
    public List<String> splitWordsBySeparator(List<String> words, char separator) {

        List<String>ans= words.stream()
                                .map(str-> str.split("["+separator+"]"))
                                .flatMap(Arrays::stream)
                                .filter(str-> !str.isEmpty())
                                .toList();

        return ans;
    }
}