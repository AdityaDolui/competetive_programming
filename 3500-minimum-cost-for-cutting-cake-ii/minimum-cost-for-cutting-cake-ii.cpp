class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
           priority_queue<pair<int,int> > pq;
        //, vector<pair<int,int>> ,greater<pair<int,int>>
         int ver=0,hori=0;
         for(auto it:horizontalCut)pq.push({it,0});
         for(auto it:verticalCut)pq.push({it,1});

        long long ans=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int num=it.first;
            int dir=it.second;
            //cout<<num<<" ";
            if(dir){
                ans+=(ver+1)*num;
                hori++;
            }else {
                ans+=(hori+1)*num;
                ver++;
                }
        }
return ans;
    }
};