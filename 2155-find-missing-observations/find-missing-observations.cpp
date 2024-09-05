class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
       vector<int> ans;
       int m=rolls.size();
       int totm=accumulate(rolls.begin(),rolls.end(),0);
    int total=mean*(m+n);
    if(total-totm>(n*6) || total<totm)return {};
    
    int rem=total-totm;

    int r=rem%n;
    int d=rem/n;
    if(!d)return {};
    while(n--){
        if(r>0){
            r--;
            ans.push_back(d+1);
        }else ans.push_back(d);
    }
return ans;
    }
};