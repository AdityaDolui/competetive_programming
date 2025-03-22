class Solution {
    public List<String> findAllRecipes(String[] recipes, List<List<String>> ingredients, String[] supplies) {
        List<String> ans=new ArrayList<>();
        int n=recipes.length;
        HashSet<String> set=new HashSet<>(Arrays.asList(supplies));
        Queue<Integer> q= new LinkedList<>();
        HashMap<String,List<Integer>> adj=new HashMap<>();

        int [] dig=new int[n];

      for(int i=0;i<ingredients.size();i++){
    List<String> list=ingredients.get(i);
    for(int j=0;j<list.size();j++){
        String curr=list.get(j);
         if(!set.contains(curr)){
            List<Integer> arr= adj.getOrDefault(curr,new ArrayList<>());
            arr.add(i);
            adj.put(curr,arr);
            dig[i]++;
         }
    }
      }

    for(int i=0;i<dig.length;i++){
        if(dig[i]==0){
            q.add(i);
        }
    }

    while(!q.isEmpty()){
        int curr=q.poll();
        ans.add(recipes[curr]);
        List<Integer> list=adj.getOrDefault(recipes[curr],new ArrayList<>());
       // System.out.println(String.valueOf(list));
        for(Integer val:list){
            dig[val]--;
            if(dig[val]==0)q.add(val);
        }
    }

        

        return ans;
    }
}