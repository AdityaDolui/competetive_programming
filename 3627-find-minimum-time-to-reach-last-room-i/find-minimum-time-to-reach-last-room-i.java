class Solution {
    int[] dx={1,0,-1,0};
    int[] dy={0,1,0,-1};
    public int minTimeToReach(int[][] moveTime) {
        PriorityQueue<int[]> pq=new PriorityQueue<>((a,b)->Integer.compare(a[0],b[0]));

        int n=moveTime.length;
        int m=moveTime[0].length;
        int[][] dist=new int[n][m];

        for(int i=0;i<n;i++)Arrays.fill(dist[i],Integer.MAX_VALUE);
        dist[0][0]=0;
        pq.offer(new int[]{0,0,0});

        while(!pq.isEmpty()){
            int [] curr=pq.poll();

            int currTime=curr[0];
            int x=curr[1];
            int y=curr[2];
      //  System.out.println(x+" "+y+" "+currTime);
            if(x==n-1 && y==m-1)return currTime;
            for(int i=0;i<4;i++){
                int xx=x+dx[i];
                int yy=y+dy[i];

                if(xx>=0 && xx<n && yy>=0 && yy<m){
                    int nextTime=Math.max(currTime,moveTime[xx][yy])+1;
                    if(nextTime<dist[xx][yy]){
                        dist[xx][yy]=nextTime;
                        pq.add(new int[]{nextTime,xx,yy});
                    }
                }
            }
        }

        return -1;

    }
}