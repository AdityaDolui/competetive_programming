class Solution {
    public int longestNiceSubarray(int[] nums) {
        int ans=1;
        int cal=nums[0];
        int l=0,h=1;
        while(h<nums.length){
           // cal=cal&nums[h];
            if((cal & nums[h]) ==0){
                ans=Math.max(ans,(h-l+1));
                cal=cal|nums[h];
                // System.out.println(l+" "+h+" ");
            }else{
            while(l<h){
                if((cal & nums[h])==0)break;
                cal=cal & ~ nums[l];
                l++;
            }
            cal=(cal | nums[h]);
            }
            
            h++;
        }
        return ans;
    }
}