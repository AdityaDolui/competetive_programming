class Solution {
    public int numOfSubarrays(int[] arr) {
        
        final int MOD=1000000007;
        long odd=0,   even=1,sum=0,result=0;

        for(int val:arr){
            sum+=val;
            if( (sum&1)==1){
                result+=even;
                result=result%MOD;
                odd++;
            }else{
                result+=odd;
                  result=result%MOD;
                even++;
            }
        }
        return (int)result;
    }
}