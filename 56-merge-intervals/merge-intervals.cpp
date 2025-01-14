class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
         vector<vector<int>> ans;
         sort(intervals.begin(),intervals.end());

         ans.push_back(intervals[0]);

         int start=intervals[0][0];
         int end=intervals[0][1];

         for(int i=0;i<intervals.size();i++){
            if(end>=intervals[i][0]){
                end=max(intervals[i][1],end);
                ans.back()[1]=end;
            }else{
                ans.push_back(intervals[i]);
                end=intervals[i][1];
            }
           
         }
          return ans;
    }
};