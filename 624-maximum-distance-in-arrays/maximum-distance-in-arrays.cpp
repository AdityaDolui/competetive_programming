class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        pair<int,int> maxi={INT_MIN,-1}, secondMaxi={INT_MIN,-1};
        pair<int,int> mini={INT_MAX,-1},secondMini={INT_MAX,-1};
        int i=0;
        for(auto it :arrays){
            int mn=*min_element(it.begin(),it.end());
            int mx=*max_element(it.begin(),it.end());
            
           if(mn<mini.first){
             secondMini=mini;
            mini={mn,i};
           
           }else if(mn<secondMini.first){
            secondMini={mn,i};
           }
           if(mx>maxi.first){
            secondMaxi=maxi;
            maxi={mx,i};
           }else if(mx>secondMaxi.first){
            secondMaxi={mx,-1};
           }
            i++;
        }

        int ans=0;
        if(maxi.second!=mini.second){
            return maxi.first-mini.first;
        }
        return max((maxi.first-secondMini.first),(secondMaxi.first-mini.first));

    }
};