class Solution {
    public int countDays(int days, int[][] meetings) {
        int ans=0;
        Arrays.sort(meetings,(a,b)->a[0]-b[0]);
        int last=0;
        for(int i=0;i<meetings.length;i++){
            ans+=meetings[i][0]>last?meetings[i][0]-last-1:0;
            last=Math.max(last,meetings[i][1]);
        }
        ans+=days-last;
        return ans;
    }
}