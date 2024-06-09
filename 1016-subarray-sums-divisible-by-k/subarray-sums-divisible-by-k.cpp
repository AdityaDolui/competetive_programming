class Solution {
public:
    int subarraysDivByK(vector<int>& time, int k) {
          int ans=0;
        int n=time.size();
        int sum=0;
        unordered_map<int,int> map;
        map[0]=1;
        for(int i=0;i<n;i++){

            sum+=time[i];
            int rem=sum%k;
                 if(rem<0)rem=rem+k;
            if(map.find(rem)!=map.end())ans+=map[rem];

            
             map[rem]++;
        }
        return ans;
    }
};