class Solution {
    public boolean divideArray(int[] nums) {
        
        return Arrays.stream(nums)
                    .boxed()
                    .collect(Collectors.groupingBy(
                        Function.identity(),Collectors.counting()))
                    .values()
                    .stream()
                    .allMatch(val-> (val&1)!=1);
    }
}