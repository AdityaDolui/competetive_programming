class Solution {
public:
      int N ;
      vector<long long> bit;
    void update(int i,int val){
        for(;i<N && i!=0;i+=(i&-i)){
            bit[i]+=val;
        }
    }
    long long sum(int i){
        long long ans=0;
        for(;i>0;i-=(i&-i)){
            ans+=bit[i];
        }
        return ans;
    }
    bool isIdealPermutation(vector<int>& nums) {
        long long global=0;
        int maxi=*max_element(nums.begin(),nums.end());
        N=maxi+2;
        bit.assign(N,0);

        for(int i=0;i<nums.size();i++){
            global+=sum(N-1)-sum(nums[i]);
            update(nums[i],1);
        }
        long long local=0;

        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i]){cout<<"hello";
            local++;}
        }
        cout<<global<<"  "<<local;
        return (local==global);
    }
};