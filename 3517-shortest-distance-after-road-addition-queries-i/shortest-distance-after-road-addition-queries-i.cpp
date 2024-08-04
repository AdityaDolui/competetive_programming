class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        
        vector<int> adj[n];
        for(int i=0;i<n-1;i++){
            adj[i].push_back(i+1);
        }
        
        for(auto it:queries ){
            adj[it[0]].push_back(it[1]);
            vector<int> dist (n,INT_MAX);
            priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
            pq.push({0,0});
            
            while(!pq.empty()){
                auto ii=pq.top();
                pq.pop();
                int curr=ii.second;
                int val=ii.first;
                if(curr==n-1){
                    ans.push_back(val);
                    break;
                }
                for(auto next:adj[curr]){
                    if(dist[next]>val+1){
                        pq.push({val+1,next});
                        dist[next]=val+1;
                    }
                }
            }
        }
        return ans;
        
        
        
        
        
        
        // vector<pair<int,int>> pair;
        // int gap=0;
        // for(int i=0;i<queries.size();i++){
        //     auto itt=queries[i];
        //     int l=itt[0];
        //     int r=itt[1];
        //     bool flag=true;
        //     for(auto &it:pair){
        //         if((l<=it.first &&  r>=it.first)||(l>=it.first &&  l<=it.second)){
        //             if(l<=it.first &&  r>=it.first){
        //                 gap+=abs(l-it.first);
        //                 it.first=l;
        //             }
        //             else{
        //                 gap++abs(it.second-r)
        //             }
        //         }
        //     }
        // }
    }
};