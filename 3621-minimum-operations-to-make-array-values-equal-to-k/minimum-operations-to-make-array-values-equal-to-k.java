class Solution {
    public int minOperations(int[] nums, int k) {
        Set<Integer> set=Arrays.stream(nums).boxed().collect(Collectors.toSet());

        boolean check=set.stream().anyMatch(val-> val<k);
        if(check==true)return -1;
        return (int) set.stream().filter(val-> val!=k).count();
       
    }
}