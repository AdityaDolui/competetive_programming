class Solution {
public:
vector<bool> SieveOfEratosthenes(int n)
{
    
   vector<bool> prime(n+1,true);
    
 
    for (int p = 2; p * p <= n; p++) {
        
        if (prime[p] == true) {
            
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
 
    return prime;
}
    int maximumPrimeDifference(vector<int>& nums) {
        //sort(nums.begin(),nums.end());
        int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());
        unordered_set<int> set;

        vector<bool> prime=SieveOfEratosthenes(maxi);
        int last=-1,first=-1;
        for(int i=2;i<prime.size();i++){
            if(prime[i])set.insert(i);
        }
    int mini=INT_MAX;
    maxi=0;
        for(int i=0;i<nums.size();i++){
            if(set.find(nums[i])!=set.end()){
                mini=min(mini,i);
                maxi=max(maxi,i);
            }
        }
        cout<<"here";
//for(int i=0;i<prime.size();i++)if(prime[i])cout<<i<<" ";

        return maxi-mini;
    }
};