class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        
        unordered_map<int,int> map;
        int cnt=0;
        vector<int> ans;
        for(int i=0;i<A.size();i++){
            map[A[i]]++;
            map[B[i]]++;

            if(A[i]==B[i]){
                  if(map[A[i]]==2)cnt++;
            }else{
                 if(map[A[i]]==2)cnt++;
            if(map[B[i]]==2)cnt++;
            }
           
            ans.push_back(cnt);
        }
        return ans;
    }
};