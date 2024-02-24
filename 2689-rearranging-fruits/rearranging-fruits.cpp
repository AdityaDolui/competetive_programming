class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int mini=INT_MAX;
        unordered_map<int,int> map1,map2;
        for(auto it:basket1){
            mini=min(mini,it);
            map1[it]++;}
        for(auto it:basket2){mini=min(mini,it);
        map2[it]++;}

        int num1=0, num2=0;

        vector<int> v1,v2;
         for(auto it :map1){
            int a=abs(it.second-map2[it.first]);
            if(a&1){
                cout<<"1st ";
                return -1;}

            if(it.second>map2[it.first])
            {
                for(int i=0;i<a/2;i++)
                v1.push_back(it.first);
                num1+=a; }
        }
        for(auto it :map2){
            int a=abs(it.second-map1[it.first]);
            if(a&1){
                 cout<<"2nd ";
                 return -1;}

            if(it.second>map1[it.first])
            {
                for(int i=0;i<a/2;i++)
                v2.push_back(it.first);
                num2+=a;} 
        }
    //   if(num1!=num2)return -1;

       sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());

        long long ans=0;
    
    int i=0;
    
      long minCost=0;
        for(int i=0;i<v1.size();i++)
        {
            int x=min(min(v1[i],v2[v1.size()-i-1]),2*mini);
            minCost+=x;
        }
            
        return minCost;

    
    cout<<"last";
    

    }
};