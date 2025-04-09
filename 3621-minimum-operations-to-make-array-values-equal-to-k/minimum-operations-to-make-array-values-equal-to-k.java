class Solution {
    public int minOperations(int[] nums, int k) {
        Set<Integer> set=Arrays.stream(nums).boxed().collect(Collectors.toSet());

        return set.stream()
                    .anyMatch(val-> val<k)? -1
                    : (int) set.stream().filter(val-> val!=k).count();

       
       
       
    }
}