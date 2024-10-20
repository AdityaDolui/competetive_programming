class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        for(auto it:arr){
            int val=abs(it-x);
            pq.push({val,it});
        }
        vector<int> ans;
        while(k-- && !pq.empty()){
            auto it=pq.top();
            pq.pop();
            ans.push_back(it.second);
        }
        sort(ans.begin(),ans.end());

        return ans;
    }
};