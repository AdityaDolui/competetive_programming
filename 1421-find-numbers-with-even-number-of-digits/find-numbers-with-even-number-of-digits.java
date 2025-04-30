class Solution {
    public int findNumbers(int[] nums) {
        return (int) Arrays.stream(nums)
                        .map(num->{
                            int n=0;
                            while(num>0){
                                num=num/10;
                                n++;
                            }
                            return n;
                        })
                        .filter(n->(n%2)==0)
                        .count();
    }
}