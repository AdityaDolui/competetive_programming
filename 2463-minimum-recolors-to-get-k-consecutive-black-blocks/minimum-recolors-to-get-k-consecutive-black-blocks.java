class Solution {
    public int minimumRecolors(String blocks, int k) {
        int mini=Integer.MAX_VALUE;
        int curr=0;
        if(blocks.length()<k) return -1;
        for(int i=0;i<k;i++)curr+=blocks.charAt(i)=='B'?1:0;
        mini=Math.min(mini,(k-curr));
        int j=0;
        for(int i=k;i<blocks.length();i++){
            curr-=blocks.charAt(j)=='B'?1:0;
            curr+=blocks.charAt(i)=='B'?1:0;
              j++;
              mini=Math.min(mini,(k-curr));
            //  System.out.println(i+" "+j+" "+curr);
        }
        return mini;
    }
}