class Solution {
public:
    vector<pair<int,int>> adj[105];     
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
     //   vector<vector<pair<int,int>>> adj(n);

        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }

        vector<int> dist(n,INT_MAX);
       // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
       queue<pair<int,pair<int,int>>> pq;
        pq.push({0,{0,src}});

        while(!pq.empty()){
        auto val=pq.front();
        int step=val.first;
        int cost=val.second.first;
        int curr=val.second.second;
        pq.pop();
      //  if(step<=k && curr==dst)return cost;
        if(step>k)continue;
        for(auto it:adj[curr]){
            if(cost+it.second<dist[it.first]){

            dist[it.first]=cost+it.second;
                pq.push({step+1,{it.second+cost,it.first}});
            }
        }
        }


        if(dist[dst]==INT_MAX)return -1;
        return dist[dst];

    }
};