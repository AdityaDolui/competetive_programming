class Solution {

    public boolean check(long mid,int[] ranks, int cars){
        
        int cnt=0;
        for(int val:ranks){
            long tar=mid/val;
            cnt+=(int) Math.sqrt(tar);
            if(cnt>=cars)return true;
        }
    
        return false;

    }
    public long repairCars(int[] ranks, int cars) {
        
        long left= 1, right=Long.MAX_VALUE;
        
        long ans=0;
        while(left<=right){
            long mid=left+(right-left)/2;

            if(check(mid,ranks,cars)){
                ans=mid;
                right=mid-1;
            }else left=mid+1;
        }
     
        return ans;
    }
}