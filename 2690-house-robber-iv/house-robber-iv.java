class Solution {

    public boolean check(int mid,int[] nums, int k ){
        int count=0;
        int i=0;
        while(i<nums.length){
            if(nums[i]<=mid){
                count++;
                i+=2;
            }else i++;
        }

        if(count>=k)return true;
       else return false;
    }
    public int minCapability(int[] nums, int k) {
        

        int left=1,right=Arrays.stream(nums).max().orElse(0);

        int ans=0;

        while(left<=right){
            int mid=left+(right-left)/2;
            if(check(mid,nums,k)){
                ans=mid;
                System.out.println(mid);
                right=mid-1;
            }else left=mid+1;
        }
        return ans;
    }
}