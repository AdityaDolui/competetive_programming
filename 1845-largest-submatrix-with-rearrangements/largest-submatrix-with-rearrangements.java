class Solution {
    public int largestSubmatrix(int[][] matrix) {
        
        int row=matrix.length;
        int col=matrix[0].length;

        int[][] temp=new int[row][col];

        for(int j=0;j<col;j++){
            int cnt=0;
            for(int i=0;i<row;i++){
                if(matrix[i][j]==1)cnt++;
                else cnt=0;
                temp[i][j]=cnt;
            }
        }
       for (int i = 0; i < matrix.length; i++) {

            temp[i]=Arrays.stream(temp[i])
                            .boxed()
                            .sorted((a,b)->b-a)
                            .mapToInt(a->a)
                            .toArray();

       }
        int ans=0;
         for(int i=0;i<row;i++){
            
            for(int j=0;j<col;j++){
                if(temp[i][j]==0)break;

                ans=Math.max(ans,temp[i][j]*(j+1));
            }
        }
       for (int[] r : temp) {
    System.out.println(Arrays.toString(r));
}
        return ans;
    }
}