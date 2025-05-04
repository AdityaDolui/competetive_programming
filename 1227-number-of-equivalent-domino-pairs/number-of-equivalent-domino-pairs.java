class Solution {
        public long cantorPair(int a, int b) {
        int x = Math.min(a, b), y = Math.max(a, b);
        long sum = x + y;
        return (sum * (sum + 1)) / 2 + y;
    }

    public int numEquivDominoPairs(int[][] dominoes) {
        int ans=0;
        Map<Long,Integer> map=new HashMap<>();

        for(int[] row :dominoes){
            long val=cantorPair(row[0],row[1]);

            ans+=map.getOrDefault(val,0);
            map.put(val,map.getOrDefault(val,0)+1);
        }
        return ans;
    }
}