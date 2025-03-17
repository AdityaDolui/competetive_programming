class Solution {
    public int hammingWeight(int n) {
       // return Integer.bitCount(n);
       int ans=0;
       while(n!=0){
        ans+=(n&1)==1?1:0;
        n=n>>1;
       }
       return ans;
    }
}