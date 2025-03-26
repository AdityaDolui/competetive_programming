class Solution {
    public int minOperations(int[][] grid, int x) {
        int[] newArr= Arrays.stream(grid)
                            .flatMapToInt(Arrays::stream)
                            .toArray();
        Arrays.sort(newArr);
    int mid=newArr[(newArr.length/2)];
        
        int cnt=0;
        for(int val:newArr){
            if(Math.abs(val-mid)%x==0)cnt+=(Math.abs(val-mid))/x;
            else return -1;
        }

    System.out.println(Arrays.toString(newArr));
        return cnt;
       
    }
}