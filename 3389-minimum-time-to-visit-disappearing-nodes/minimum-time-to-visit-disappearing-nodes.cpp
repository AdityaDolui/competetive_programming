class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<int> ans(n,INT_MAX);
        vector<pair<int,int>> adj[n+1];
        
            for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][2],edges[i][1]});
            adj[edges[i][1]].push_back({edges[i][2],edges[i][0]});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        ans[0]=0;
        vector<bool> vis(n+1,false);
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int val=it.first;
            int curr=it.second;
            if(vis[curr])continue;
            vis[curr]=1;
            for(auto iit:adj[curr]){
                int nextVal=iit.first;
                int next=iit.second;
                if(val+nextVal<ans[next]){
                    if(disappear[next]<=val+nextVal) continue;
                   else { ans[next]=val+nextVal;
                    pq.push({ans[next],next});
                    }
                }
            }
        }
        for(auto &it:ans)if(it==INT_MAX)it=-1;
        return ans;
    }
};