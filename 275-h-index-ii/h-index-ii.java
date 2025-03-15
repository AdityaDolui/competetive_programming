class Solution {
    public boolean check(int mid, int[] citations){
        int cnt=0;
        for(int val:citations){
            if(val>=mid)cnt++;
        }
        return cnt>=mid? true:false;
    }
    public int hIndex(int[] citations) {
        int left=1 , right=citations.length;

        int ans=0;
        while(left<=right){
            int mid=left+(right-left)/2 ;
            if(check(mid,citations)){
                ans=mid;
                left=mid+1;
            }else right=mid-1;
        }
        return ans;
    }
}