class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        vector<pair<int,int>> maxEl, minEl;
        int i=0;
        for(auto it :arrays){
            int mini=*min_element(it.begin(),it.end());
            int maxi=*max_element(it.begin(),it.end());
            maxEl.push_back({maxi,i});
            minEl.push_back({mini,i});
            i++;
        }

        sort(maxEl.begin(),maxEl.end());
        sort(minEl.begin(),minEl.end());

        int ans=0;
        int m=maxEl.size();
        if(maxEl[m-1].second!=minEl[0].second){
            return maxEl[m-1].first-minEl[0].first;
        }
        return max((maxEl[m-1].first-minEl[1].first),(maxEl[m-2].first-minEl[0].first));

    }
};