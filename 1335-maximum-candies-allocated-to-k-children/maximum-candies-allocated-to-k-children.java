class Solution {
    public boolean check(int ans,int[] candies, long k){
       
       int i=0,r=candies.length-1;
       long count=0;
       int rem=0;
        
        for(int val:candies){
            count+=val/ans;
            if(count>=k)return true;
        }

    
        return false;

    }
    public int maximumCandies(int[] candies, long k) {
      
        int ans=0;
        System.out.println(Arrays.toString(candies));
        int left=1,right=Arrays.stream(candies).max().orElse(0);
        while(left<=right){
            int mid=left+(right-left)/2;
            if(check(mid,candies,k)){
                ans=mid;
                left=mid+1;
            }else{
                    right=mid-1;
            }
        }
return ans;
    }
}