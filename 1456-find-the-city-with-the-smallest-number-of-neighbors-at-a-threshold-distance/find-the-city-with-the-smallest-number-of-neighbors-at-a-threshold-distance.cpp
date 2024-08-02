class Solution {
public:
int f(int source , int remain,int n, vector<vector<pair<int,int>>> &adj){
   priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
   unordered_set<int> set;
   
    q.push({source,0});
    //vector<bool> vis(n,false);
    vector<int> dist (n+1,INT_MAX);
    dist[source]=0;
    while(!q.empty()){
        auto it=q.top();

        int i=it.first;
        int cnt=it.second;
        q.pop();

      
        
        set.insert(i);

        for(auto iit:adj[i]){
            int next=iit.first;
            int nextCost=iit.second;
            if(dist[next]>cnt+nextCost && cnt+nextCost<=remain ){
                dist[next]=cnt+nextCost;
                q.push({next,cnt+nextCost});
            }
                    }
       
    }
    return set.size()-1;
}
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        

    vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        int ans=-1;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            int val=f(i,distanceThreshold,n,adj);
            cout<<i<<"-"<<val<<"  ";
            if(val<=mini){
                mini=val;
                ans=i;
                
            }
        }
        return ans;

        
    }
};