class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
       // vector<int> balls(limit+1,-1);
        vector<int> ans;
        unordered_map<int,int> map,balls;
        for(int i=0;i<queries.size();i++){
            // if(map.find(queries[i][1]).map.end()){
                
                
                
            
                int currball=queries[i][0];
           int color=queries[i][1];

            if(balls.find(currball)!=balls.end()){
                map[balls[currball]]--;
                if(map[balls[currball]]<=0){
                 //   cout<<map.size()<<" ";
                    map.erase(balls[currball]);
                 //cout<<map.size()<<" ";
                }
}
    map[queries[i][1]]++;
            balls[currball]=color;
            ans.push_back(map.size());
             
        }
        return ans;
    }
};