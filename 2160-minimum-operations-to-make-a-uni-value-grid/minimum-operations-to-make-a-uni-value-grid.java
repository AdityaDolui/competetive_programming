class Solution {
    public int minOperations(int[][] grid, int x) {
        int[] newArr= Arrays.stream(grid)
                            .flatMapToInt(Arrays::stream)
                            .sorted()
                            .toArray();
       
    int mid=newArr[(newArr.length/2)];
        
        return Arrays.stream(newArr)
                        .map(val-> Math.abs(val-mid)%x==0?Math.abs(val-mid)/x:-1)
                        .reduce(0,(a,b)-> b==-1?-1:(a==-1?-1:a+b));
  
       
    }
}