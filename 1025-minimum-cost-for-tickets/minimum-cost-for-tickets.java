class Solution {
    int f(int i,int day,int[] days, int[] costs,int [][] dp){
        if(day>=days[days.length-1]){
            return 0;
        }
        
        if(dp[i][day]!=-1)return dp[i][day];
        if(day>=days[i]){
            return f(i+1,day,days,costs,dp);
        }
        int first=f(i+1,days[i],days,costs,dp)+costs[0];
        int second=f(i+1,days[i]+6,days,costs,dp)+costs[1];
        int third=f(i+1,days[i]+29,days,costs,dp)+costs[2];

        return dp[i][day]=Math.min(first,Math.min(second,third));

    }
    public int mincostTickets(int[] days, int[] costs) {
        int [][] dp=new int[days.length][400];
        Arrays.stream(dp).forEach(row-> Arrays.fill(row,-1));
        return f(0,0,days,costs,dp);
    }
}