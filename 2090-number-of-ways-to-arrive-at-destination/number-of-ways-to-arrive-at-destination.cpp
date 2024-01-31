class Solution {
public:
int mod = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
       for (int i = 0; i < roads.size(); i++)
        {
            // {u, v, w}
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
       // vector<int> vis(n,0);
        vector<long long> dist(n,1e15);
        vector<int> cnt(n,0);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        pq.push({0,0});
        dist[0]=0;
        cnt[0]=1;
        while(!pq.empty()){
            long long w=pq.top().first;
            int curr=pq.top().second;
            pq.pop();
          //  if(vis[curr])continue;
          //  vis[curr]=1;
            if(curr==n-1)break;

            for(auto it: adj[curr]){
                int next=it.first;
                    long long nextdist=it.second;
                if(nextdist+w<dist[next]){
                    
                    dist[next]=nextdist+w;
                    cnt[next]=cnt[curr];
                    pq.push({nextdist+w,next});
                }
                else if(nextdist+w==dist[next])cnt[next]=(cnt[next]+cnt[curr])%mod;
            }
        }
        return cnt[n-1]%mod;
    }
};