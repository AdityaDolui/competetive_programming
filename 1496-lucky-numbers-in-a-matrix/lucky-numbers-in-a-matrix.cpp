class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> ans;
        vector<int> col(m);
        for(int i=0;i<m;i++){
            int maxi=0;
            for(int j=0;j<n;j++){
                maxi=max(maxi,matrix[j][i]);
            }
            col[i]=maxi;
        }

        for(int i=0;i<n;i++){
            int mini=*min_element(matrix[i].begin(),matrix[i].end());
            for(int j=0;j<m;j++){
                if(col[j]==mini)ans.push_back(mini);
            }
        }
return ans;
    }
};