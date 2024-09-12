class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        priority_queue<int> pq;

        int sum1=0,sum2=0;
            sum1=accumulate(nums1.begin(),nums1.end(),sum1);
         sum2=accumulate(nums2.begin(),nums2.end(),sum2);

         if(sum1==sum2)return 0;

         if(sum1>sum2){
            for(auto it:nums1){
                if(it-1)pq.push((it-1));
            }
             for(auto it:nums2){
                if(6-it)pq.push((6-it));
            }
         }else{
            for(auto it:nums2){
                if(it-1)pq.push((it-1));
            }
             for(auto it:nums1){
                if(6-it)pq.push((6-it));
            }
         }

         int diff=abs(sum1-sum2);
         int ans=0;
         while(diff>0){
            if(pq.empty())return -1;
            diff-=pq.top();
            pq.pop();
            ans++;
         }
return ans;
    }
};