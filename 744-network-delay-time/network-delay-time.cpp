class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
      vector<vector<int>> adj[n+1];  

        for(int i=0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
            //node                          nextNode        weight?//
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;
        pq.push({0,k});
        
        while(!pq.empty()){
            auto it=pq.top();
            int node=it.second;
            int weight=it.first;
            pq.pop();
            for(auto it:adj[node]){
                int nextNode=it[0];
                int nextWeight=it[1];
                if(dist[nextNode] > (weight+nextWeight)){
                dist[it[0]]=weight+it[1];
                pq.push({dist[it[0]],it[0]});
                }
            }
        }
        int ans=0;
        for(int i=1;i<dist.size();i++){
           // cout<<it<<" ";
            ans=max(ans,dist[i]);
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};