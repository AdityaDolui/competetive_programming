class Solution {
public:
pair<int,int> diraction(int i,string &s){
    if(s[i]=='U')return {-1,0};
     if(s[i]=='D')return {1,0};
      if(s[i]=='R')return {0,1};
       if(s[i]=='L')return {0,-1};
       else{
       
           return {0,0};
       } 
}
int f(int k,int i,int j, int n,string &s ){
   // if(i<0 || i>=n || j>=n )return 0;
    
    if(k>=s.length()){
      //  cout<<
    return 0;}

    auto it=diraction(k,s);
    int x=i+it.first;
    int y=j+it.second;
   if(x<0 || x>=n || y<0 || y>=n)return 0;
    return 1+f(k+1,x,y,n,s);

}
    vector<int> executeInstructions(int n, vector<int>& pos, string s) {
        vector<int> ans;
        for(int i=0;i<s.length();i++) ans.push_back(f(i,pos[0],pos[1],n,s));

        return ans;

    } 
};