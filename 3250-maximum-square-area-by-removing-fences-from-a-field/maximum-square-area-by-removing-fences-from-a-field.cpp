class Solution {
public:
    int mod=1e9+7;
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(m);
        hFences.push_back(1);
        vFences.push_back(n);
        vFences.push_back(1);
        //int i=min(hFences.size(),vFences.size());
        int i=hFences.size();
        int j=vFences.size();
        sort(hFences.begin(),hFences.end());
        sort(vFences.begin(),vFences.end());

        int ans=-1;
        unordered_set<int> v,h;
        for(int k=0;k<i;k++){
        //    cout<<hFences[k]<<" ";
            for(int l=k+1;l<i;l++){
                h.insert(hFences[l]-hFences[k]);
            }
        }
     //   cout<<endl;
        for(int k=0;k<j;k++){
      //        cout<<vFences[k]<<" ";
            for(int l=k+1;l<j;l++){
                v.insert(vFences[l]-vFences[k]);
            }
        }
     //   cout<<endl;

        int maxi=0;
        for(auto it : v){
       //     cout<<it<<" ";
            if(h.find(it)!=h.end()){
       //         cout<<"here->"<<it<<"-";
                maxi=max(maxi,it);
            }
        }
        if(maxi==0)return -1;
        else {
         //   maxi--;
            return (1LL*maxi*maxi)%mod;
        }
        
    }
};