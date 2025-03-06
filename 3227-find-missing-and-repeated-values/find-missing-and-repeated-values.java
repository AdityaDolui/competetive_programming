class Solution {
    public int[] findMissingAndRepeatedValues(int[][] grid) {
        int[] ans=new int[2];

       // HashSet<Integer> set=new HashSet<>();

       int [] arr=new int[(grid.length*grid.length)];
        int k=0;
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[0].length;j++){
                
                if(arr[grid[i][j]-1]!=0){
                    ans[0]=grid[i][j];
                }
                arr[grid[i][j]-1]=1;
                
            }
        }

    for(int i=0;i<arr.length;i++){
        if(arr[i]==0){
            ans[1]=i+1;
        break;}
    }
    return ans;


    }
}