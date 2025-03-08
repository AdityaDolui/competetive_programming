class Solution {
    public int removeDuplicates(int[] nums) {
          int n=nums.length;
        int j=2;
       // int ans=2;
          if(n < 3) return n;

        for(int i=2;i<n;i++){
            if(nums[i]==nums[j-2]){
               // continue;
            }
            else {
             //   ans++;
            nums[j++]=nums[i];
            }
        }
        return j;
    }
}