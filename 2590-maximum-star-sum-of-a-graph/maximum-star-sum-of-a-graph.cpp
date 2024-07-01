class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        vector<int> adj[n];
        
        // create adjacency list of graph
        for(int i=0 ; i<edges.size() ; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        // create a maxi variable to store ans.
        int maxi = INT_MIN;
        
        for(int i = 0 ; i<n ; i++){
            int tmp = vals[i];
            // create min heap to store vals
            priority_queue<int , vector<int> , greater<int>> pq;
            for(auto it:adj[i]){
               pq.push(vals[it]);
            // we have to take k edges that's why we have to remove extra value from heap (we remove top value bcoz min heap contain minimum value on its top)
               if(pq.size()>k){
                   pq.pop();
               }
            }
            // for each node store the k centered values in tmp.
            while(!pq.empty()){
                if(pq.top()>0)
                    tmp += pq.top();
                pq.pop();   
            }
            // store the maximum value in maxi.
            maxi = max(maxi , tmp);
        }
        return maxi;
    }
};