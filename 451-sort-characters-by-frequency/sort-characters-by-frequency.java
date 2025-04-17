class Solution {
    public String frequencySort(String s) {
        return s.chars()
                .mapToObj(ch->(char)ch)
                .collect(Collectors.groupingBy(st->st))
                .values()
                .stream()
                .sorted((a,b)->Long.compare(b.size(),a.size()))
                .flatMap(List::stream)
                .map(String::valueOf)
                .collect(Collectors.joining());
    }
}