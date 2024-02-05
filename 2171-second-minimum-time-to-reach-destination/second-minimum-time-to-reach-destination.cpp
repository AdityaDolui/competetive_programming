class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n+1);
        for(auto it: edges){
            adj[it[0]-1].push_back(it[1]-1);
            adj[it[1]-1].push_back(it[0]-1);
        }
          vector<priority_queue<int>> distArr(n+1);
        for(int i=0;i<n;i++)distArr[i].push(1e8);

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});

      

        distArr[0].pop();
        distArr[0].push(0);

        vector<int> vis(n+1,0);
       // pq.push()

       while(!pq.empty()){
           int curr=pq.top().second;
           int dist=pq.top().first;
           pq.pop();
           
        int k=dist/change;
        if((k%2)==1)dist+=(change-(dist%change));
          
           

           for(auto it: adj[curr]){
               int nextDist=dist+time;

               if(distArr[it].top()==1e8){
                   distArr[it].pop();
                   distArr[it].push(nextDist);
                   pq.push({nextDist,it});
               }
               else if(distArr[it].size()<2 && distArr[it].top()!=nextDist){
                   distArr[it].push(nextDist);
                   pq.push({nextDist,it});
               }
               else{
                   if(distArr[it].top()>nextDist){
                       distArr[it].pop();
                   distArr[it].push(nextDist);
                   pq.push({nextDist,it});
                   }
               }
           }
       }
       return  distArr[n-1].top();

    }
};