class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int cnt=0;
        
        unordered_map<string,int> map;
        for(auto it:arr){
            map[it]++;
        }  
       
        for(auto it:arr){
            if(map[it]==1){cnt++;
            if(cnt==k)return it;
            }
        }
        return "";
    }
};