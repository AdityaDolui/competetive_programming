class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n=energy.size();
        vector<int> arr(energy.size(),-1e9);
        int ans=INT_MIN;
        for(int i=0;i<energy.size();i++){
            if(arr[i]==-1e9){
                if(i+k>=n){
                    ans=max(ans,energy[i]);
                }else{
                    arr[i+k]=energy[i];
                    }
            }else{
                if(arr[i]>0){
                      if(i+k>=n){
                    ans=max(ans,(energy[i]+arr[i]));
                }else{
                          arr[i+k]=arr[i]+energy[i];
                    }
                
                }else{
                    if(i+k>=n){
                    ans=max(ans,max(energy[i],(arr[i]+energy[i])));
                }else{
                          arr[i+k]=max(energy[i],(arr[i]+energy[i]));
                    }
                    
}
            }
}       
        return ans;
    }
};