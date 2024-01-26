class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        
        vector<pair<double,int>> adj[n];
              for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({succProb[i],edges[i][1]});
            adj[edges[i][1]].push_back({succProb[i],edges[i][0]});

        }
    for(auto it:adj){
        for(auto iit :it)cout<<iit.first<<" ";
    }
        vector<double> dist (n,DBL_MIN);
        vector<bool> vis(n,false);
        priority_queue<pair<double,int>> pq;

        pq.push({1.0,start_node});
       // vis[start_node]=1;
        dist[start_node]=1.0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            double d=it.first;
            int curr=it.second;
           // if(i==end_node)return it.second;
           if(vis[curr])continue;
           cout<<"HI"<<curr<<" ";
                vis[curr]=true;
                for(auto ii:adj[curr]){
                    int next=ii.second;
                    double nextDist=ii.first;
                    cout<<next<<"-"<<next;
                    if(dist[next]<dist[curr]*nextDist){
                        cout<<"yes"<<" ";
                        dist[next]=dist[curr]*nextDist;
                        pq.push({dist[next],next});
                    }
                }
            
        }
       // for(auto it:dist)cout<<it<<" ";
        return dist[end_node];
    }
};