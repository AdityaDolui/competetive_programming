class Solution {
    public int removeElement(int[] nums, int val) {
        
        int ans=nums.length;
   
        int i=0;
        int k=nums.length-1;
        while(i<=k){
            if(nums[i]==val){
                int temp=nums[i];
                nums[i]=nums[k];
                nums[k]=nums[i];
                k--;
                ans--;
            }else{
                i++;
            }
        }
        return ans;
    }
}