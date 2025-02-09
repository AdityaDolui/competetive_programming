class Solution {
    public long countBadPairs(int[] nums) {
        HashMap<Integer,Integer> map=new HashMap<>();
        long ans=0;
        int cnt=0;
        int [] newArr=Arrays.copyOf(nums,nums.length);
        Arrays.sort(newArr);
         map.put((nums[nums.length-1]-(nums.length-1)), 1);
        for(int i=nums.length-2;i>=0;i--){
             int match=map.getOrDefault((nums[i]-i),0);
             ans+=nums.length-i-match-1;
           //  System.out.println(i+" -> "+ans+" "+match);
             map.put((nums[i]-i),map.getOrDefault((nums[i]-i),0)+1);
        }
        return ans;
    }
}