class Solution {
    public void bfs(int curr,boolean[] vis, List<Integer>  count,List<List<Integer>> adj){
        Queue<Integer> q=new LinkedList<>();

        q.add(curr);
        vis[curr]=true;
        while(!q.isEmpty()){
            int val=q.poll();

            count.add(val);
                List<Integer> list=adj.get(val);
                list.forEach(it->{
                    if(!vis[it]){
                        vis[it]=true;
                        q.add(it);
                       // System.out.println(val);
                      
                    }
                });
            
        }
    }
    public int countCompleteComponents(int n, int[][] edges) {
         List<List<Integer>> adj = new ArrayList<>(n);
         for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }

        for(int i=0;i<edges.length;i++){
            adj.get(edges[i][0]).add(edges[i][1]);
             adj.get(edges[i][1]).add(edges[i][0]);
        }

        boolean [] vis =new boolean[n];
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
              //  System.out.println(i);
               List<Integer> list=new ArrayList<>();
                bfs(i,vis,list,adj);
                 // System.out.println(count[0]+" "+adj.get(i).size());
               
                boolean flag= list.stream().allMatch(it-> list.size()-1==adj.get(it).size());
                ans+=flag==true?1:0;
            }
        }
        return ans;
    }
}