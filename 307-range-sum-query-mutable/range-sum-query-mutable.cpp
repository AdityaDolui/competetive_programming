class NumArray {
public:
// const int N = 1e5+10;
// int bit[N];

vector<int> bit;
vector<int> arr;
    NumArray(vector<int>& nums) {
        int n=nums.size();
        bit.assign(n+1,0);
        arr=nums;
     //   for(auto it:nums)cout<<it<<" ";
        for(int i=0;i<n;i++){
            updateTree(i,arr[i]);
        }
    }
    
    void updateTree(int index, int val) {
        index++;
        for(int i=index;i<=arr.size();i+=i&(-i)){
            bit[i]+=val;
        }
    }
     void update(int i, int val) {
        int diff = val-arr[i];
        arr[i] = val;
        i = i+1;
        while(i<=arr.size()){
            bit[i]+=diff;
            i+=i&(-i);
        }
    }
    int sum(int i){
        i++;
        int ans=0;
        for(;i>0;i-=(i&-i)){
            ans+=bit[i];
        }
        return ans;
    }
    
    int sumRange(int left, int right) {
        return (sum(right)-sum(left-1));
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */