#define ll long long
class Solution {
public:
     int countBit(ll val){
         int ans=0;
         while(val){
             val=val>>1;
             ans++;
         }
         return ans;
     }
     ll powerOf2(int i){
         return 1LL << i;
     }
    ll value(ll val, int x){

        int cnt=countBit(val);
        val++;
        ll ans=0;
        int i=1;
        while(i<=cnt){
            if((i%x)==0){
                ans+=(val/powerOf2(i)*powerOf2(i-1))+ max(0LL,(val%powerOf2(i))-powerOf2(i-1));
            }
            i++;
        }
        return ans;

    }
    long long findMaximumNumber(long long k, int x) {
        
        ll low=0, high =1e15,mid;
        ll ans;

        while(low<=high){
            mid=(high - low) / 2 + low;
            ll cnt=value(mid,x);
            if(cnt<=k){
               // ans=cnt;
                low=mid+1;
            }else high=mid-1;
        }
        return high;
    }
};