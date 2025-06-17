class Solution {
      int [] dx=new int[]{1,0,-1,0};
     int [] dy=new int[]{0,1,0,-1};

    public int[][] highestPeak(int[][] mat) {
        
        Queue<Pair<Integer,Integer>> q=new LinkedList<>();

        for(int i=0;i<mat.length;i++){
            for(int j=0;j<mat[0].length;j++){
                if(mat[i][j]==1){
                    q.add(new Pair<>(i,j));
                    mat[i][j]=0;
                }else mat[i][j]=Integer.MAX_VALUE;
            }
        }

        while(!q.isEmpty()){
            Pair<Integer,Integer> p=q.poll();
            int i=p.getKey();
            int j=p.getValue();

            for(int k=0;k<4;k++){
                int x=i+dx[k];
                int y=j+dy[k];
                if(x>=0 && x<mat.length && y>=0 && y<mat[0].length && mat[x][y]>mat[i][j]+1){
                    mat[x][y]=mat[i][j]+1;
                    q.add(new Pair<>(x,y));
                }
            }

        }
        return mat;
    }
}