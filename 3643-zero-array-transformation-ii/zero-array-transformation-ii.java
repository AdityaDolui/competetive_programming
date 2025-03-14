class Solution {
    public boolean check(int mid,int[] nums, int[][] queries){
          int n=nums.length;
     int[] arr=new int[n+1];
   // return true;
    for(int i=0;i<mid;i++){
        arr[queries[i][0]]+=queries[i][2];
         arr[queries[i][1]+1]-=queries[i][2];
    }

    int maxi=0;
    int pre=0;
    
    for(int i=0;i<n;i++){
        pre+=arr[i];
        if(pre<nums[i]) return false;
    }
    return true;
    }
    public int minZeroArray(int[] nums, int[][] queries) {
      
      int ans=-1;
      int left=0, right = queries.length;
      while(left<= right){
        int mid=left + (right-left)/2;
        if(check(mid,nums,queries)){
            right=mid-1;
            ans=mid;
        }else left=mid+1;
      }
    return ans;
    }
}