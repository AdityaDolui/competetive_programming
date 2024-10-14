class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans=0;
        priority_queue<int> pq;

        for(auto it:nums){
            pq.push(it);
        }

        while(k--){
            if(!pq.empty()){
                ans+=pq.top();
                int val=pq.top();
                pq.pop();
                if(val%3){
                    pq.push((val/3)+1);
                }else{
                    pq.push(val/3);
                }
            }
        }
        return ans;
    }
};