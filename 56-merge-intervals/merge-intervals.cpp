class Solution {
public:
 //bool 
    vector<vector<int>> merge(vector<vector<int>>& intr) {
         vector<vector<int>> ans;
         sort(intr.begin(),intr.end());
        int l=intr[0][0],h=intr[0][1];
        vector<int> temp;
        if(intr.size()==1)return {{intr[0][0],intr[0][1]}};
         for(int i=1;i<intr.size();i++){
             
             
             if(intr[i][0]<=h){
             h=max(intr[i][1],h);  
                      
             }
             else {
                    ans.push_back({l,h});
                    l=intr[i][0];
                    h=intr[i][1];
             }
              if(i==intr.size()-1)ans.push_back({l,h});
             
         }
         return ans;
    }
};