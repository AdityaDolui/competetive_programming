class Solution {
public:
int count (vector<int>& arr){
    vector<int> ans;
    
    for(auto it:arr){
        if(ans.empty() || it>ans.back()){
            ans.push_back(it);
        }
        else{
            int i=lower_bound(ans.begin(),ans.end(),it)-ans.begin();
            ans[i]=it;
        }
    }
   
    return ans.size();
}
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> map;
        int n=target.size();
        int m=arr.size();
        for(int i=0;i<n;i++){
            map[target[i]]=i;
        }

        vector<int> temp;
        for(auto it:arr){
            if(map.find(it)!=map.end())temp.push_back(map[it]);
        }
        
    int len=count(temp);
    return n-len;
    }
};