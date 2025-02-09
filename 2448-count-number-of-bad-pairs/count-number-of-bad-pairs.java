class Solution {
    public long countBadPairs(int[] nums) {
        HashMap<Integer,Integer> map=new HashMap<>();
        long ans=0;
       
         
         map.put((nums[nums.length-1]-(nums.length-1)), 1);
        for(int i=nums.length-2;i>=0;i--){
             int match=map.getOrDefault((nums[i]-i),0);
             ans+=nums.length-i-match-1;
            
             map.put((nums[i]-i),map.getOrDefault((nums[i]-i),0)+1);
        }
        return ans;
    }
}