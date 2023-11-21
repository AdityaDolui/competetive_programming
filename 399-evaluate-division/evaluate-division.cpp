class Solution {
public:
    void dfs(string curr, string &dest,unordered_set<string>& vis,unordered_map<string,vector<pair<double,string>>> & adj,double & val,double & res){
        if(vis.find(curr)!=vis.end())return ;
        vis.insert(curr);
        if(curr==dest){
            res=val;
            return;
        }

        for(auto it: adj[curr]){
            if(vis.find(it.second)==vis.end()){
                val*=it.first;
                dfs(it.second,dest,vis,adj,val,res);
                val=val/it.first;
            }
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        vector<double> ans;
        unordered_map<string,vector<pair<double,string>>> adj;

        for(int i=0;i<equations.size();i++){
            string strt=equations[i][0];
            string dest=equations[i][1];
            adj[strt].push_back({values[i],dest});
            adj[dest].push_back({(1.0/values[i]),strt});
        }
   //    cout<<adj["c"][0].first;
//
        for(auto it:queries){
            if(adj.find(it[0])==adj.end() || adj.find(it[1])==adj.end()){
                cout<<"Y ";
             ans.push_back(-1.0);
                
            }else{
                unordered_set<string> vis;
                double val=1.0,res=-1.0;
                dfs(it[0],it[1],vis,adj,val,res);
                ans.push_back(res);
            }
        }



    return ans;
    }
};