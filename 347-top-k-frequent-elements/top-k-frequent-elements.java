class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        return Arrays.stream(nums)
                    .boxed()
                     .collect(Collectors.groupingBy(s->s,Collectors.counting()))
                     .entrySet()
                     .stream()
                     .sorted((a,b)->Long.compare(b.getValue(),a.getValue()))
                     .limit(k)
                     .mapToInt(entry->entry.getKey())
                     .toArray();
    }
}