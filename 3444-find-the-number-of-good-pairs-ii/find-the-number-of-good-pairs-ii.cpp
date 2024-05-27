class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        unordered_map<long long,int> map;
        for(auto it:nums2){
            map[it*k]++;
        }
      
        long long ans=0;
        for(auto it:nums1){
            
            for(int j=1;j<=sqrt(it);j++){
                if(it%j==0){
                int divd=it/j;

                if(divd!=j && map.find(divd)!=map.end())ans+=map[divd];
                if(map.find(j)!=map.end())ans+=map[j];

                
                }
}
}
      //  cout<<endl;
        return ans;
            
    }
};