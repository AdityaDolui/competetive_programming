class Solution {
    public int[] countBits(int n) {
        int[] ans=new int[n+1];
        while(n>=0){
            ans[n]=Integer.bitCount(n);
            n--;
        }
        return ans;
    }
}