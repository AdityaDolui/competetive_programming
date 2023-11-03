class Solution {
public:
int ans;
    void check(unordered_map<int,int> map,int k){
        int cnt=0;
        bool flag=1;
        int x,a,div;
        for(auto it:map){
            x=it.second;
             if(x%(k+1)==0){
                cnt+=x/(k+1);
            }else{
                    div=x%(k+1);
                     a=x/(k+1);
                    if(div==0){
                        cnt+=a;
                        continue;
                    }
                    if(a>=(k-div)){
                        cnt+=a+1;
                        continue;
                    }
                    flag=0;
                    break;
            }
        }
        if(flag){
            cout<<k<<"-"<<cnt<<"  ";
            ans=min(ans,cnt);
        }
    }
    int minGroupsForValidAssignment(vector<int>& nums) {
     unordered_map<int,int> map;
        for(auto it:nums)map[it]++;
       int h=INT_MAX;;
       for(auto it:map)h=min(h,it.second);
        int l=1;
         ans=INT_MAX;
        while(l<=h){
            check(map,l);
           l++;
        }
        return ans;
    }
};