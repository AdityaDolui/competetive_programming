class Solution {
    public int removeDuplicates(int[] nums) {
        //int[] arr=System.arraycopy();
       int[] arr=Arrays.stream(nums).distinct().toArray();
       System.arraycopy(arr,0,nums,0,arr.length);
       return arr.length;
    }
}