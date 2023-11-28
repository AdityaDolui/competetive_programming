class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBar, vector<int>& vBar) {
        sort(hBar.begin(),hBar.end());
        sort(vBar.begin(),vBar.end());
    int cnt=0;
    int hmax=0;
    for(int i=0;i<hBar.size()-1;i++){
        if(hBar[i+1]==hBar[i]+1){
            cnt++;
            hmax=max(hmax,cnt);
       
        }else cnt=0;
    }   
    cnt=0;
    int vmax=0;
    for(int i=0;i<vBar.size()-1;i++){
        if(vBar[i+1]==vBar[i]+1){
            cnt++;
            vmax=max(vmax,cnt);
        }else cnt=0;
    }   
    int mini=min(hmax,vmax);
    mini+=2;
    return (mini*mini);  
    }
};