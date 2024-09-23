class Solution {
public:
int mod=1e9+7;
    int maximumProduct(vector<int>& nums, int k) {
        
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto it:nums)pq.push(it);

        while(k--){
            int val=pq.top();
            pq.pop();
            val++;
            pq.push(val);
        }
        long long ans=1;
        while(!pq.empty()){
            ans=((pq.top()%mod)*ans)%mod;
            pq.pop();
        }
        return (int)ans;
    }
};