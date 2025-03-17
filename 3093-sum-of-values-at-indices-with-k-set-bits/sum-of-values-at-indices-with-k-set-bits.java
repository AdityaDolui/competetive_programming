class Solution {
    public int sumIndicesWithKSetBits(List<Integer> nums, int k) {
        int ans=0;
        
        for(int i=0;i<nums.size();i++){
            ans+=Integer.bitCount(i)==k?nums.get(i):0;
        }

        return ans;
    }
}