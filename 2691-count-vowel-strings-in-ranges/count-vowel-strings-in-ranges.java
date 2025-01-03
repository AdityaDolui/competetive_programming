class Solution {
    public int[] vowelStrings(String[] words, int[][] queries) {
        HashSet<Character> set=new HashSet<>(Arrays.asList('a','e','i','o','u'));
      

        int [] ans=new int [queries.length];
         int [] pre=new int[words.length];

    if(set.contains(words[0].charAt(0)) && set.contains(words[0].charAt(words[0].length()-1)) ){
        pre[0]=1;
    }
        for(int i=1;i<words.length;i++){
            if(set.contains(words[i].charAt(0)) && set.contains(words[i].charAt(words[i].length()-1)) ){
                pre[i]=pre[i-1]+1;
            }else{
                pre[i]=pre[i-1];
            }

        }
        int i=0;
        for(int[] arr: queries){
            if(arr[0]==0){
                ans[i]=pre[arr[1]];
            }else{
                 ans[i]=pre[arr[1]]-pre[arr[0]-1];
            }
            i++;
        }
        System.out.println(Arrays.toString(pre));
        return ans;
    }
}