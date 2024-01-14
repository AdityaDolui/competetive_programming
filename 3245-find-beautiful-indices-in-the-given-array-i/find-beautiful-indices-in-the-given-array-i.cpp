class Solution {
public:
  
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> ans;
        
        vector<int> arrb,arra;
        int st,en;
        size_t pos=s.find(a);
       
        while(pos!=string ::npos){
            arra.push_back(pos);
            pos=s.find(a,pos+1);
        }
        pos=s.find(b);

         while(pos!=string ::npos){
            arrb.push_back(pos);
            pos=s.find(b,pos+1);
        }
        int i=0,j=0;
        while(i<arra.size() && j<arrb.size()){
            if(abs(arra[i]-arrb[j])<=k){

            ans.push_back(arra[i]);
            i++;
          //  j++;
            }
            else if(arra[i]>arrb[j])j++;
            else i++;
        }
        
    //    for(auto it:arra)cout<<it<<" ";
    //     for(auto it:arrb)cout<<it<<" ";
        
        
        
        return ans;
        
    }
};