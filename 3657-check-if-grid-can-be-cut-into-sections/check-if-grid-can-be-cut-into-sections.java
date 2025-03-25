class Solution {
    boolean check(int[][] rectangles, int n){
        Arrays.sort(rectangles,(a,b)->a[0]-b[0]);
        int cnt=0;
        int last=rectangles[0][1];
        for(int i=1;i<rectangles.length;i++){
            if(rectangles[i][0]<last){
                last=Math.max(last,rectangles[i][1]);
            }else{
                cnt++;
                last=rectangles[i][1];
            }
            if(cnt==2)return true;
        }
        return false;

    }
    public boolean checkValidCuts(int n, int[][] rectangles) {
        int [][] x=new int[rectangles.length][2];
        int [][] y=new int[rectangles.length][2];
        for(int i=0;i<rectangles.length;i++){
            x[i][0]=rectangles[i][0];
            x[i][1]=rectangles[i][2];
            y[i][0]=rectangles[i][1];
            y[i][1]=rectangles[i][3];
        }

        return (check(x,n)||check(y,n));
    }
}