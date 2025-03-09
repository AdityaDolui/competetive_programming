class Solution {
    public void rotate(int[] nums, int k) {
          k=k%nums.length;
        reverse(nums,0,nums.length-1);
        reverse(nums,0,k-1);
        reverse(nums,k,nums.length-1);
    }
    void reverse(int[] nums, int l, int h){
        int temp;
        while(l<h){
            temp=nums[l];
            nums[l]=nums[h];
            nums[h]=temp;
            l++;
            h--;
        }
    }
}