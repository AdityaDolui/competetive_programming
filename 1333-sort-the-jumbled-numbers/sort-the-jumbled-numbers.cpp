class Solution {
public:
    int mappedValue(vector<int>& mapping,int num){
        
     int ans=0;
     int i=1;
     if(num==0)ans=mapping[0];
        while(num){
            int rem=(num%10);
            ans+=(i*mapping[rem]);
            num/=10;
            i*=10;
        }
        cout<<ans<<"  ";
        return ans;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<int> ans;
        int k=0;
        vector<pair<int,int>> v;
        for(int i=0;i<nums.size();i++){
            int val=mappedValue(mapping,nums[i]);
            v.push_back({val,k++});
        }

    sort(v.begin(),v.end());
    for(auto it:v){
        ans.push_back(nums[it.second]);
    }
    return ans;
    }
};