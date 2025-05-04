class Solution {
    public int minDominoRotations(int[] tops, int[] bottoms) {
     Map<Integer,List<Integer>> topMap=new HashMap<>();
      Map<Integer,List<Integer>> bottomMap=new HashMap<>();

      for(int i=0;i<tops.length;i++){
        int it=tops[i];
        topMap.computeIfAbsent(it, k -> new ArrayList<>()).add(i);
      }

    int ans=Integer.MAX_VALUE;
     for(int i=0;i<bottoms.length;i++){
        int it=bottoms[i];
          bottomMap.computeIfAbsent(it, k -> new ArrayList<>()).add(i);
      }

      for(Map.Entry<Integer,List<Integer>> entry:topMap.entrySet()){
        int key=entry.getKey();
        List<Integer> list=entry.getValue();
         List<Integer> list2=bottomMap.getOrDefault(key,new ArrayList<>());
         int val=(int)Stream.concat(list.stream(),list2.stream())
         .distinct()
         .count();

         if(val==tops.length){
            ans= Math.min(ans,(tops.length-list.size()));
             ans= Math.min(ans,(tops.length-list2.size()));

         }
      }
      if(ans==Integer.MAX_VALUE)return -1;
      return ans;

    }
}